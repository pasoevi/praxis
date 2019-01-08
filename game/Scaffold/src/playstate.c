#include "gameworld.h"

int globalTime = 0;

static struct Sprite *player;
static struct Sprite *enemy;
struct GameWorld *world;
extern List *bullets;
extern List *ledges;
extern int playerScore;

extern int WINDOW_W;
extern int WINDOW_H;

#define CAPTION_OFFSET 20

int LIVES_LOC_X = CAPTION_OFFSET;
int LIVES_LOC_Y = CAPTION_OFFSET;

#define SCORE_LOC_X (WINDOW_W - CAPTION_OFFSET)
int SCORE_LOC_Y = CAPTION_OFFSET;

/* Camera */
int LEVEL_W = 800 * 2;
int LEVEL_H = 600 * 2;

struct Camera camera = {{0, 0, 640, 400}};

TTF_Font *themeFont = NULL;
SDL_Texture *backgroundTexture = (void*)NULL;
extern SDL_Texture *brickTexture;
extern SDL_Texture *bulletTexture;

int loadTextures(SDL_Renderer *renderer){
	LoadImage("graphics/sheet.png", (SDL_Texture**)&(player->texture), renderer);
	LoadImage("graphics/Biomechanical.png",
		  (SDL_Texture**)&(enemy->texture), renderer);
	LoadImage("graphics/bullet.png", (SDL_Texture**)&bulletTexture, renderer);
	LoadImage("graphics/bricks.png", (SDL_Texture**)&brickTexture, renderer);
	LoadImage("graphics/landscape_3.png",
		  (SDL_Texture**)&backgroundTexture, renderer);
}

static void renderScore(struct GameState *game, int score){
	char scoreTxt[10];
	sprintf(scoreTxt, "%d", score);
	DrawText(game->renderer, scoreTxt, SCORE_LOC_X - 20, SCORE_LOC_Y, themeFont,
		 0xFF, 0xFF, 0xFF);
}

static void renderLives(struct GameState *game, int lives){
	char livesTxt[2];
	sprintf(livesTxt, "%d\0", lives);
	DrawText(game->renderer, livesTxt, LIVES_LOC_X, LIVES_LOC_Y, themeFont, 0xFF,
		 0x0, 0x0);
}

static void renderBackground(struct GameState *game, struct Camera *camera){
	/* DrawImage(backgroundTexture, 0, 0, 1280, 800, 0, SDL_FLIP_NONE,
	   game->renderer); */
	SDL_Rect body = {0, 0, 800, 600};
	SDL_Rect camBody =
		{camera->rect.x, camera->rect.y, camera->rect.w, camera->rect.h};
	DrawImageOnCamera(backgroundTexture, body, &camBody, 0, NULL, SDL_FLIP_NONE,
			  game->renderer);
}

extern int isKeyDown(SDL_Scancode);

static struct GameState pauseState;
static struct GameState gameoverState;

void toPauseMode(struct GameStateMachine *fsm) {
	struct GameState *thisState =
		(struct GameState*) list_tail(fsm->gameStates)->data;
	pauseState = (struct GameState){
		&pauseUpdate,
		&pauseDraw,
		&pauseOnEnter,
		&pauseOnExit,
		GAME_STATE_PAUSE,
		thisState->renderer
	};
	fsm->pushState(fsm, &pauseState);
}

void toGameoverMode(struct GameStateMachine *fsm) {
	struct GameState *thisState =
		(struct GameState*) list_tail(fsm->gameStates)->data;
	gameoverState = (struct GameState){
		&gameoverUpdate,
		&gameoverDraw,
		&gameoverOnEnter,
		&gameoverOnExit,
		GAME_STATE_GAMEOVER,
		thisState->renderer
	};
	fsm->changeState(fsm, &gameoverState);
}

void playerUpdateMouse(void *playerParam){
	struct Sprite *player = (struct Sprite*) playerParam;
	/* Update player using MOUSE
	   struct Vec2d mousePos;
	   SDL_GetMouseState(&(mousePos.x), &(mousePos.y));
	   player->vel = subtract(mousePos, player->pos);
	   player->vel = divideByScalar(player->vel, 10);
	   player->pos = add(player->pos, player->vel);
	*/
}

void playUpdate(void *fsm_param) {
	struct GameStateMachine *fsm = (struct GameStateMachine*) fsm_param;

	/* Look for Escape */
	if (isKeyDown(SDLK_ESCAPE)){
		toPauseMode(fsm);
	}

	/* Call update function for the player */
	player->update(world);
	/* Center the camera over the dot */
	camera.rect.x = (player->pos.x + player->w / 2) - WINDOW_W / 2;
	camera.rect.y = (player->pos.y + player->h / 2) - WINDOW_H / 2;

	/* Keep the camera in bounds */
	if(camera.rect.x < 0){
		camera.rect.x = 0;
	}
	if(camera.rect.y < 0){
		camera.rect.y = 0;
	}
	if(camera.rect.x > LEVEL_W - camera.rect.w){
		camera.rect.x = LEVEL_W - camera.rect.w;
	}
	if(camera.rect.y > LEVEL_H - camera.rect.h){
		camera.rect.y = LEVEL_H - camera.rect.h;
	}

	updateBullets(bullets);

	/* enemy->update(world); */
	globalTime++;
}

void playDraw(struct GameState *state) {
	SDL_SetRenderDrawColor(state->renderer, 230, 120, 20, 255);
	renderBackground(state, &camera);
	renderLedges(ledges, 10, state->renderer);
	renderScore(state, playerScore);
	renderLives(state, world->lives);
	drawSprite(player, &camera, state->renderer);
	drawSprite(enemy, &camera, state->renderer);
	drawBullets(bullets, state->renderer);
  
	SDL_SetRenderDrawColor(state->renderer, 230, 120, 20, 255);
}

int initFonts(void){
	if ( TTF_Init() < 0 ) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM,
			     "Couldn't initialize TTF: %s\n", SDL_GetError());
		SDL_Quit();
		return(2);
	}
	themeFont = TTF_OpenFont("fonts/djserifi.ttf", 26);
}

int initBackground(struct GameState *game){}

int playOnEnter(struct GameState *state) {
	initFonts();
	/* initialise the game world */
	world = malloc(sizeof(struct GameWorld));
	world->lives = 3;
	world->level_w = LEVEL_W;
	world->level_h = LEVEL_H;
	world->window_w = WINDOW_W;
	world->window_h = WINDOW_H;
	player = malloc(sizeof(struct Sprite));
	enemy = malloc(sizeof(struct Sprite));
	if (player == NULL || enemy == NULL){
	  return -1;
	}
	int imgW, imgH;
	makeSprite(player, 6, DEFAULT_HIT_POINTS, (struct Vec2d){ 300, 300 },
		   (struct Vec2d){ 0, 10 });

	player->update = playerUpdate;
	makeSprite(enemy, 2, DEFAULT_HIT_POINTS, (struct Vec2d){ 750, 300 },
		   (struct Vec2d){ 0, 3 });

	enemy->update = enemyUpdate;
	player->texture = (void *)NULL;
	enemy->texture = (void*)NULL;
	loadTextures(state->renderer);

	SDL_QueryTexture(player->texture, NULL, NULL, &imgW, &imgH);
	player->w = imgW / player->numFrames;
	player->h = imgH;
	player->state = IDLE;
	player->facing = RIGHT;

	SDL_QueryTexture(enemy->texture, NULL, NULL, &imgW, &imgH);
	enemy->w = imgW / enemy->numFrames;
	enemy->h = imgH;
	
	enemy->pos.x = 400;
	enemy->pos.y = 600;
	enemy->vel.x = 1;
	enemy->vel.y = 1;
	world->player = player;
	world->enemy = enemy;

	bullets = malloc(sizeof *bullets);
	list_init(bullets, NULL);
	
	ledges = malloc(sizeof *ledges);
	list_init(ledges, destroyLedge);
	initLedges(ledges, state->renderer);
	world->ledges = ledges;
	
	initBackground(state);
	return 0;
}

int playOnExit(void) {
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Exited playstate");
	SDL_DestroyTexture(player->texture);
	SDL_DestroyTexture(backgroundTexture);
	SDL_DestroyTexture(brickTexture);
	/* TTF_CloseFont(themeFont); */
	return 1;
}

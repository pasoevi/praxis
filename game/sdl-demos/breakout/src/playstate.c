#include <stdlib.h>
#include "gameworld.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include "keyboard.h"
#include "collision.h"

int globalTime = 0;
struct GameWorld *world;
extern int playerScore;

extern int WINDOW_W;
extern int WINDOW_H;
extern int FPS;

static void renderBackground(struct GameState *game){

}

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
		thisState->context
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
		thisState->context
	};
	fsm->changeState(fsm, &gameoverState);
}

void playUpdate(void *fsm_param) {
  struct GameStateMachine *fsm = (struct GameStateMachine*) fsm_param;
	/* Call update function for the player */
	world->paddle->update(world);
	world->ball->update(world);
	/* updateBricks(world); */
	handleBallBrickCollisions(world->ball, world->bricks);
	globalTime++;
}

void playDraw(struct GameState *state) {
	glClear(GL_COLOR_BUFFER_BIT);
	renderBricks(world->bricks);
	world->paddle->render(world->paddle);
	world->ball->render(world->ball);
}

int initFonts(void){
	
}

int playOnEnter(struct GameState *state) {
	initFonts();
	
	/* initialise the game world */
	world = malloc(sizeof(struct GameWorld));
	world->lives = 3;
	world->window_w = WINDOW_W;
	world->window_h = WINDOW_H;
	
	/* Create the paddle */
	struct Paddle *paddle = malloc(sizeof(struct Paddle));
	paddle->update = paddleUpdate;
	paddle->render = paddleRender;
	paddle->w = 190;
	paddle->h = 40;
	paddle->pos = (struct Vec2d){WINDOW_W / 2 - paddle->w /2, WINDOW_H - paddle->h};
	
	/* Create a ball */
	struct Ball *ball = malloc(sizeof(struct Ball));
	ball->update = ballUpdate;
	ball->render = ballRender;
	ball->w = 10;
	ball->h = 10;
	ball->pos = (struct Vec2d){WINDOW_W / 2 - ball->w / 2, WINDOW_H / 2 - ball->h / 2};
	ball->vel = (struct Vec2d){2, 2};

	/* Create bricks */
	List *bricks = malloc(sizeof bricks);
	list_init(bricks, destroyBrick);
	initBricks(bricks);
	
	/* Add all the objects to the game world */
	world->ball = ball;
	world->paddle = paddle;
	world->bricks = bricks;
	world->bricks = bricks;
	
	return 0;
}

int playOnExit(void) {
	if(world != NULL){
		free(world->ball);
		free(world->paddle);
		free(world);
	}
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Exited playstate");
	return 1;
}

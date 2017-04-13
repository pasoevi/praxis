#include <stdlib.h>
#include "gameworld.h"
#include "ship.h"
#include "bullet.h"
#include "brick.h"
#include "keyboard.h"
#include "collision.h"

int globalTime = 0;
struct GameWorld *world;
extern int playerScore;

extern int WINDOW_W;
extern int WINDOW_H;
extern int FPS;

extern void destroy(void* data);

static void renderBackground(struct GameState *game){}

const char * getLevelFile(int level){
        static char filename[50];
        sprintf(filename, "levels/%d.xml", level);
        return filename;
}

void initLevel(struct GameWorld *world, int level){
        const char *levelFile = getLevelFile(level);
        parseLevel(world, levelFile);
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
        world->ship->update(world->ship, world);
        updateBricks(world);
        updateBullets(world);
        handleKeys(world);
        handleBulletBrickCollisions(world->bullets, world->bricks);
	handleShipEnemyCollisions(world->ship, world->bricks);
        handleShipEnemyCollisions(world->ship, world->bullets);

        /* Change the level when no enemies remain */
        if(list_size(world->bricks) == 0){
                SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                            "Level %d cleared.", world->level);
                if(world->level < world->maxLevel){
                        world->level++;
                        initLevel(world, world->level);
                }else{
                        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                                    "All levels cleared.", world->level);
                }
        }
        globalTime++;
}

void playDraw(struct GameState *state) {
        glClear(GL_COLOR_BUFFER_BIT);
        renderBricks(world->bricks);
        renderPowerups(world->powerups);
        world->ship->render(world->ship);
        renderBullets(world->bullets);
}

int initFonts(void){}

struct GameWorld * initWorld(void){
        struct GameWorld *world = malloc(sizeof *world);
        world->level = 1;
        world->maxLevel = 5;
        world->lives = 3;
        world->windowW = WINDOW_W;
        world->windowH = WINDOW_H;
        return world;
}

int playOnEnter(struct GameState *state) {
        initFonts();

        /* initialise the game world */
        world = initWorld();

        /* Create the ship */
        world->ship = initShip();

        /* Initialise the empty bullet list */
        world->bullets = initBullets();

        /* Create bricks */
        world->bricks = initBricks();

        /* Create powerups */
        world->powerups = initPowerups();

        /* parse and initialise the level, that is, load the enemies,
         * powerups, etc from the xml file. */
        initLevel(world, world->level);
        return 0;
}

int playOnExit(void) {
        if(world != NULL){
                list_destroy(world->bullets);
                list_destroy(world->bricks);
                list_destroy(world->powerups);
                free(world->ship);
                free(world);
        }
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Exited playstate");
        return 1;
}

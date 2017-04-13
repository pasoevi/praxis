/*
  Copyright (C) 2015, 2016 Sergi Pasoev.

  This pragram is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or (at
  your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.

  Written by Sergi Pasoev <s.pasoev@gmail.com>
*/

#include <stdlib.h>
#include "ship.h"
#include "bullet.h"
#include "powerup.h"
#include "brick.h"
#include "keyboard.h"
#include "collision.h"
#include "parselvl.h"

int globalTime = 0;
struct GameWorld *world;
extern int playerScore;
extern int WINDOW_W;
extern int WINDOW_H;
extern int FPS;

extern void destroy(void* data);

const char * getLevelFile(int level){
        static char filename[50];
        sprintf(filename, "levels/%d.xml", level);
        return filename;
}

void initLevel(int level){
        const char *levelFile = getLevelFile(level);
        parseLevel(world, levelFile);
}

static struct GameState pauseState;
static struct GameState gameoverState;

void toPauseMode(struct GameStateMachine *fsm) {
        struct GameState *thisState =
                (struct GameState*) list_tail(fsm->gameStates)->data;
        pauseState.update = pauseUpdate;
	pauseState.render = pauseDraw;
	pauseState.onEnter = pauseOnEnter;
	pauseState.onExit = pauseOnExit;
        pauseState.stateId = GAME_STATE_PAUSE;
	pauseState.context = thisState->context;

        fsm->pushState(fsm, &pauseState);
}

void toGameoverMode(struct GameStateMachine *fsm) {
        struct GameState *thisState =
                (struct GameState*) list_tail(fsm->gameStates)->data;
        gameoverState.update = gameoverUpdate;
	gameoverState.render = gameoverDraw;
	gameoverState.onEnter = gameoverOnEnter;
	gameoverState.onExit = gameoverOnExit;
	gameoverState.stateId = GAME_STATE_GAMEOVER;
	gameoverState.context = thisState->context;
	
        fsm->changeState(fsm, &gameoverState);
}

void playUpdate(void *fsm_param) {
        /* struct GameStateMachine *fsm = (struct GameStateMachine*) fsm_param; */
        /* Call update function for the player */
        world->ship->update(world->ship, world);
        updateBricks(world);
        updatePowerups(world);
        updateBullets(world);
        handleBulletBrickCollisions(world->bullets, world->bricks);
        handleShipEnemyCollisions(world->ship, world->bricks);
        handleShipPowerupCollisions(world->ship, world->powerups);
        handleShipEnemyCollisions(world->ship, world->bullets);

        /* Change the level when no enemies remain */
        if(list_size(world->bricks) == 0){
                SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                            "Level %d cleared.", world->level);
                if(world->level < world->maxLevel){
                        world->level++;
                        initLevel(world->level);
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

struct GameWorld * initWorld(void){
        world = malloc(sizeof *world);
        world->level = 1;
        world->maxLevel = 5;
        world->lives = 3;
        world->windowW = WINDOW_W;
        world->windowH = WINDOW_H;
        return world;
}

int playOnEnter(struct GameState *state) {
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
        initLevel(world->level);

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

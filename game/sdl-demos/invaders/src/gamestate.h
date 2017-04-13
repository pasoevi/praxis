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

#ifndef _GAMESTATE_H
#include <SDL2/SDL.h>
#include "list.h"
#include "geometry.h"
#include <stdlib.h>

#define GAME_STATE_PLAY 0
#define GAME_STATE_PAUSE 1
#define GAME_STATE_MENU 2
#define GAME_STATE_GAMEOVER 3

struct GameState {
        void (*update)(void *fsm);
        void (*render)(struct GameState *state);
        int (*onEnter)(struct GameState *state);
        int (*onExit)(void);
        int stateId;
        SDL_GLContext *context;
};

struct GameStateMachine {
        List *gameStates;
        void (*pushState)(struct GameStateMachine *fsm, struct GameState *state);
        void (*changeState)(struct GameStateMachine *fsm, struct GameState *state);
        void (*popState)(struct GameStateMachine *fsm);
        void (*popAllStates)(struct GameStateMachine *fsm);
};

int initFSM(List *states, void(*destroy)(void*), struct GameStateMachine** fsm);

enum button_state {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        CLICKED = 2
};

struct Menu {
        int w;
        int h;
        SDL_Texture *texture;
        int currentFrame;
        struct Vec2d pos;
        void (*onClick)(struct GameStateMachine *);
};

void pushState(struct GameStateMachine *fsm, struct GameState *state);
void changeState(struct GameStateMachine *fsm, struct GameState *state);
void popState(struct GameStateMachine *fsm);
void popAllStates(struct GameStateMachine *fsm);

/* Menu State */
void menuDraw(struct GameState *);
void menuUpdate(void *);
int menuOnEnter(struct GameState *);
int menuOnExit(void);

/* Play State */
void playDraw(struct GameState *);
void playUpdate(void *);
int playOnEnter(struct GameState *);
int playOnExit(void);

/* Pause State */
void pauseDraw(struct GameState *);
void pauseUpdate(void *);
int pauseOnEnter(struct GameState *);
int pauseOnExit(void);

/* Gameover State */
void gameoverDraw(struct GameState *);
void gameoverUpdate(void *);
int gameoverOnEnter(struct GameState *);
int gameoverOnExit(void);

#endif

/*
 * File:   scaffold.c
 * Author: sergi
 *
 * Created on December 25, 2014, 3:03 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scaffold.h"

#define PROGRAM_NAME "Scaffold"
/* Default resolution. */
int WINDOW_W = 800, WINDOW_H = 600;

int running = 1;
const Uint8 *keystates;

#define FPS 60
#define DELAY_TIME (1000.f / FPS)

int init(SDL_Window **window, SDL_Renderer **renderer){
	int success = -1;
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) >= 0) {
		/* Dynamically set the windos size to full screen*/
		/* queryResolution(&WINDOW_W, &WINDOW_H); */
		*window = SDL_CreateWindow(PROGRAM_NAME, SDL_WINDOWPOS_UNDEFINED,
					   SDL_WINDOWPOS_UNDEFINED,
					   WINDOW_W, WINDOW_H, SDL_WINDOW_OPENGL);
		if(*window == NULL){
			SDL_LogError(SDL_LOG_CATEGORY_VIDEO,
				     "Window could not be created! SDL Error: %s\n",
				     SDL_GetError());
			success = -2;
		} else{
			*renderer = SDL_CreateRenderer(*window, -1,
						       SDL_RENDERER_ACCELERATED |
						       SDL_RENDERER_PRESENTVSYNC);
			success = 1;
		}
	}
	return success;
}

void processEvents(void) {
	SDL_Event event;
	if(SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT:
			running = 0;
			break;
		}
		keystates = SDL_GetKeyboardState(0);
	}
}

int isKeyDown(SDL_Scancode key) {
	if(keystates != 0) {
		return keystates[key];
	}
	return 0;
}

void destroy(void* param) {
	printf("That's how you kill it");
}

void queryResolution(int *x, int *y) {
	SDL_DisplayMode current;
	int i = 0;
	for(i = 0; i < SDL_GetNumVideoDisplays(); ++i) {
		int should_be_zero = SDL_GetCurrentDisplayMode(i, &current);
		if(should_be_zero != 0) {
			/* In case of error... */
			SDL_LogError(SDL_LOG_CATEGORY_VIDEO,
				     "Could not get display mode for video display #%d: %s",
				     i, SDL_GetError());
		} else {
			/* On success, assign globals and print the current display mode. */
			*x = current.w;
			*y = current.h;
			SDL_LogInfo(SDL_LOG_CATEGORY_VIDEO,
				    "Display #%d: current display mode is %dx%dpx @ %dhz. \n",
				    i, current.w, current.h, current.refresh_rate);
		}
	}
}

int main(int argc, char* argv[]) {
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	List states;

	struct GameStateMachine tmpFSM;
	struct GameState menuState;
	struct GameState playState;

	Uint32 frameStart, frameTime;

	struct GameStateMachine *fsm;
	if(init(&window, &renderer) < 0){
		return -1;
	}

	list_init(&states, destroy);
	tmpFSM = (struct GameStateMachine){
		&states, pushState, changeState, popState, popAllStates
	};
	/* fsm = &(struct GameStateMachine){
	   &states, &pushState, &changeState, &popState, &popAllStates
	   };*/
	fsm = &tmpFSM;
	/* initFSM(&states, destroy, &fsm); */

	menuState = (struct GameState){
		&menuUpdate, &menuDraw, &menuOnEnter, &menuOnExit,
		GAME_STATE_MENU, renderer
	};

	/* Used for debugging the play mode */

	playState = (struct GameState){
		&playUpdate, &playDraw, &playOnEnter, &playOnExit,
		GAME_STATE_PLAY, renderer
	};

	fsm->pushState(fsm, &playState);

	while(list_size(fsm->gameStates) > 0 && running){
		frameStart = SDL_GetTicks();
		struct GameState *currentState = (struct GameState*)
			(list_tail(fsm->gameStates)->data);
		processEvents();
		currentState->update(fsm);
		SDL_RenderClear(renderer);
		currentState->render(currentState);
		SDL_RenderPresent(renderer);
		frameTime = SDL_GetTicks() - frameStart;
		if(frameTime < DELAY_TIME){
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}
	/* quit(window, renderer); */

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return EXIT_SUCCESS;
}

void quit(SDL_Window *window, SDL_Renderer *renderer){

}

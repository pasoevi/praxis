#include "gamestate.h"
#include "texture.h"
#include "geometry.h"
#include <stdio.h>
#include <SDL2/SDL.h>

struct Menu menus[2];

extern int WINDOW_W;
extern int WINDOW_H;

static struct GameState menuState;

void toMenu(struct GameStateMachine *fsm) {
	struct GameState *thisState =
		(struct GameState*) list_tail(fsm->gameStates)->data;
	menuState = (struct GameState){
		&menuUpdate, &menuDraw, &menuOnEnter, &menuOnExit,
		GAME_STATE_MENU, thisState->renderer
	};
	fsm->changeState(fsm, &menuState);
}

void pauseUpdate(void *fsm_param) {
	struct GameStateMachine *fsm = (struct GameStateMachine*) fsm_param;
	Uint32 button;
	int x, y;
	int b_released = 1;
	button = SDL_GetMouseState(&x, &y);

	int i;
	for (i = 0; i < 2; i++) {
		if (x > menus[i].pos.x && x < menus[i].pos.x + menus[i].w / 3 &&
		    y > menus[i].pos.y && y < menus[i].pos.y + menus[i].h) {
			if (button & SDL_BUTTON(1) && b_released) {
				menus[i].currentFrame = CLICKED;
				menus[i].onClick(fsm);
				b_released = 0;
			}
			else {
				menus[i].currentFrame = MOUSE_OVER;
				b_released = 1;
			}
		}
		else {
			menus[i].currentFrame = MOUSE_OUT;
		}
	}
}


void pauseDraw(struct GameState *state) {
	SDL_SetRenderDrawColor(state->renderer, 30, 120, 220, 255);
	SDL_RenderClear(state->renderer);
	int i;
	for (i = 0; i < 2; i++) {
		DrawImageFrame(menus[i].texture,
			       menus[i].pos.x,
			       menus[i].pos.y,
			       menus[i].w / 3,
			       menus[i].h, 1,
			       menus[i].currentFrame,
			       0,
			       SDL_FLIP_NONE,
			       state->renderer);
	}
}
void resume(struct GameStateMachine *fsm){
	SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Resume\n");
	fsm->popState(fsm);
}
int pauseOnEnter(struct GameState *state) {
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Entered pausestate");
	int status =
		LoadImage("graphics/resume.png", &(menus[0].texture), state->renderer);
	status +=
		LoadImage("graphics/main_menu.png", &(menus[1].texture), state->renderer);
	SDL_QueryTexture(menus[0].texture, NULL, NULL, &menus[0].w, &menus[0].h);
	SDL_QueryTexture(menus[1].texture, NULL, NULL, &menus[1].w, &menus[1].h);

	menus[0].pos.x = WINDOW_W / 2 - (menus[0].w / 3) / 2;
	menus[0].pos.y = WINDOW_H / 2 - menus[0].h / 2;

	menus[1].pos.x = menus[0].pos.x;
	menus[1].pos.y = menus[0].pos.y + menus[0].h + 10;

	menus[0].onClick = &resume;
	menus[1].onClick = &toMenu;

	menus[0].currentFrame = MOUSE_OUT; /* start at frame 0 */
	menus[1].currentFrame = MOUSE_OUT; /* start at frame 0 */

	return status;
}

int pauseOnExit(void) {
	int i;
	for (i = 0; i < 2; i++) {
		SDL_DestroyTexture(menus[i].texture);
	}
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Exited pausestate");
	return 1;
}

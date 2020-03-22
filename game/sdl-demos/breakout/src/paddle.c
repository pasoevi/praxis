#include "paddle.h"
#include "drawing.h"

void paddleUpdate(void *worldParam){
	struct GameWorld *world = (struct GameWorld *)worldParam;
	if(isKeyDown(SDL_SCANCODE_LEFT)){
		int newX = world->paddle->pos.x - STEP_SIZE;
		/* if the paddle isn't going farther than the left edge */
		if(newX >= 0){
			world->paddle->pos.x = newX;
		}else{
			/* now move paddle to the left with a shorter step than STEP_SIZE */
			if(STEP_SIZE - abs(newX) > 0){
				(world->paddle->pos.x) -= STEP_SIZE - abs(newX);
			}
		}
	}else if(isKeyDown(SDL_SCANCODE_RIGHT)){
		int newX = world->paddle->pos.x + STEP_SIZE;
		if(newX + world->paddle->w <= world->window_w){
			world->paddle->pos.x = newX;
		}else{
			/* now move paddle to the right with a shorter step than STEP_SIZE */
			int difference = abs((newX + world->paddle->w) - world->window_w);
			if(world->paddle->pos.x + world->paddle->w + difference <= world->window_w){
				(world->paddle->pos.x) += difference;
			}
		}
		
	}
}

void paddleRender(struct Paddle *paddle){
	/* Render quad */
	drawRectangle(paddle->pos, paddle->w, paddle->h);
}

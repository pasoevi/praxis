#ifndef PADDLE_H
#define PADDLE_H
#include <SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "geometry.h"
#include "keyboard.h"
#include "gameworld.h"
#include <math.h>

enum {
	STEP_SIZE = 7
};

struct Paddle{
	struct Vec2d pos;
	int w;
	int h;
	void (*update)(void *world);
	void (*render)(struct Paddle *paddle);
};

void paddleUpdate(void *);
void paddleRender(struct Paddle *paddle);


#endif

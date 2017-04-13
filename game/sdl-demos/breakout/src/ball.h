#ifndef BALL_H
#define BALL_H
#include "gameworld.h"
#include <stdlib.h>
#include <time.h>

struct Ball{
	struct Vec2d pos;
	struct Vec2d vel;
	int w, h;
	void (*update)(void *world);
	void (*render)(struct Ball *ball);
};

void ballUpdate(void *);
void ballRender(struct Ball *ball);

#endif

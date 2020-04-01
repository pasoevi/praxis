#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include <stdio.h>
#ifndef GAMESTATE_H
#include "gamestate.h"
#endif
#ifndef GEOMETRY_H
#include "geometry.h"
#endif
/* #include "brick.h" */
#include "paddle.h"
#include "ball.h"

struct GameWorld {
	struct Paddle *paddle;
	struct Ball *ball;
	List *bricks;
	int lives;
	int window_w;
	int window_h;
	void (*update)(void *world);
};

#endif

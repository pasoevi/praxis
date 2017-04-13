#ifndef BRICK_H
#define BRICK_H
#include "gameworld.h"
#include "list.h"
#include "drawing.h"
#include <stdbool.h>

struct Brick{
	struct Vec2d pos;
	int w;
	int h;
	int lives;
	void (*update)(struct Brick *brick, void *world);
	void (*render)(struct Brick *brick);
};

int initBricks(List *bricks);
void addBrick(List *bricks, int x, int y, int w, int h,
	      const char *texturefilename);

void brickUpdate(struct Brick *brick, void *world);
void brickRender(struct Brick *brick);
void destroyBrick(void *);

void updateBricks(void *worldParam);
void renderBricks(List *bricks);




#endif

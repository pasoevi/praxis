#include "brick.h"

int initBricks(List *bricks){
	int numBricks = 0;
	numBricks = parseBricks(bricks, "levels/objects.xml", addBrick);
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
		    "Loaded game objects: %d\n", numBricks);
	return numBricks;
}

void addBrick(List *bricks, int x, int y, int w, int h,
	      const char *texturefilename){
	struct Brick *brick = malloc(sizeof (struct Brick));
	brick->pos = (struct Vec2d){x, y};
	brick->w = w;
	brick->h = h;
	brick->lives = 1;
	brick->update = brickUpdate;
	brick->render = brickRender;
	list_ins_next(bricks, list_tail(bricks), brick);
}

void brickUpdate(struct Brick *brick, void *world){

}

void brickRender(struct Brick *brick){
	if(brick->lives > 0){
		drawRectangle(brick->pos, brick->w, brick->h);
	}
}

void updateBricks(void *worldParam){
	struct GameWorld *world = (struct GameWorld *)worldParam;
	ListElmt *elmt;
	for(elmt = list_head(world->bricks); elmt != NULL; elmt = list_next(elmt)){
		struct Brick *brick = list_data(elmt);
		if(brick->lives == 0){
			/* Delete brick */
			list_rem(world->bricks, elmt, (void **)&brick);
			free(brick);
			SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Brick deleted");
		}
	}

}

void renderBricks(List *bricks){
	ListElmt *elmt;
	for(elmt = list_head(bricks); elmt != NULL && list_size(bricks) > 0; elmt = list_next(elmt)){
		struct Brick *brick = list_data(elmt);
		brick->render(brick);
	}
}

void destroyBrick(void *brick){
	if(brick != NULL){
		free(brick);
	}
}

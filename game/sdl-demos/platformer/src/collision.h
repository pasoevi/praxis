#include <stdbool.h>
#include <SDL2/SDL.h>
#include "bullet.h"
#include "brick.h"
#include "list.h"

bool collidingFromLeft(struct Sprite *bullet, struct Sprite *brick);
bool collidingFromAbove(struct Sprite *bullet, struct Sprite *brick);
bool collidingFromRight(struct Sprite *bullet, struct Sprite *brick);
bool collidingFromBelow(struct Sprite *bullet, struct Sprite *brick);

/* Handle collisions: Updates bullet and bricks! */
int handleBulletBrickCollisions(List *bullets, List *bricks);

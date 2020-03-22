#include <stdbool.h>
#include <SDL2/SDL.h>
#include "ball.h"
#include "brick.h"
#include "list.h"

bool collidingFromLeft(struct Ball *ball, struct Brick *brick);
bool collidingFromAbove(struct Ball *ball, struct Brick *brick);
bool collidingFromRight(struct Ball *ball, struct Brick *brick);
bool collidingFromBelow(struct Ball *ball, struct Brick *brick);

/* Handle collisions: Updates ball and bricks! */
void handleBallBrickCollisions(struct Ball *ball, List *bricks);

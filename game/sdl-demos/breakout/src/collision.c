#include "collision.h"

bool collidingFromLeftRight(struct Ball *ball, struct Brick *brick){
	bool colliding = false;
	int ballX, ballY, brickX, brickY;
	ballX = ball->pos.x;
	ballY = ball->pos.y;
	brickX = brick->pos.x;
	brickY = brick->pos.y;
	if(ball->pos.y <= brickY + brick->h && ball->pos.y + ball->h >= brickY &&
	   ballX + ball->w >= brickX && ballX <= brickX + brick->w){
		colliding = true;
		/* SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
			    "Colliding from LEFT to the brick: x = %d, y = %d",
			    brickX, brickY);
		*/
	}

	return colliding;
}

void handleBallBrickCollisions(struct Ball *ball, List *bricks){
	if(list_size(bricks) > 0){
		ListElmt *elmt = list_head(bricks);
		for(elmt = list_head(bricks); elmt != NULL; elmt = list_next(elmt)){
			struct Brick *brick = list_data(elmt);
			if(brick->lives > 0){
				bool colliding = false;
				if(collidingFromLeftRight(ball, brick)){
					colliding = true;
					if(ball->pos.y + ball->h / 2 >= brick->pos.y + brick->h){
						//Hit was from below the brick
						ball->vel.y = -1 * ball->vel.y;
					}else if(ball->pos.y - ball->h / 2 <= brick->pos.y){
						//Hit was from above the brick
						ball->vel.y = -1 * ball->vel.y;
					}else if(ball->pos.x + ball->w / 2 < brick->pos.x){
						//Hit was on left
						ball->vel.x = -1 * ball->vel.x;
					}else if(ball->pos.x + ball->w / 2 > brick->pos.x + brick->w){
						//Hit was on right
						ball->vel.x = -1 * ball->vel.x;
					}
				}
				if(colliding){
					brick->lives--;
				}
			}
		
		}
	}
}

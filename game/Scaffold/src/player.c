#include "gameworld.h"
#ifndef TEXTURE_H
#include "texture.h"
#endif
#include "bullet.h"
#include "sprite.h"

#define PROXIMITY 300
#define COLLISION 2

extern int globalTime;

int playerScore = 0;
int playerLives = 3;

extern struct Vec2d enemyPos, enemyVel;
extern int WINDOW_W; /* only for bullets */
extern int WINDOW_H;

extern int isKeyDown(SDL_Scancode);

List *bullets;
SDL_Texture *bulletTexture = (void *)NULL;

struct Vec2d gravity = {0, -1};

void initPlayer(void){}

static struct Sprite *player;

int collidingBelow(List *ledges, struct Sprite *player){
	struct Ledge *collidingLedge = NULL;
	int collidingBelow = 0;
	ListElmt *elmt;
	int playerLeftX = player->pos.x;
	int playerRightX = player->pos.x + player->w;
	int playerY = player->pos.y + player->h;
	for(elmt = list_head(ledges); elmt != NULL; elmt = list_next(elmt)){
		struct Ledge *ledge = (struct Ledge *)list_data(elmt);
		int ledgeY = ledge->y, ledgeLeftX = ledge->x, ledgeRightX = ledge->x + ledge->w;
		if(playerRightX >= ledgeLeftX && playerLeftX <= ledgeRightX &&
		   playerY >= ledgeY && playerY <= ledgeY + 10){
			collidingBelow = 1;
		}
	}
	return collidingBelow;
}

void shoot(struct Sprite* sprite){
	sprite->state = SHOOTING;
	if(sprite->currentFrame == 4){
		sprite->currentFrame = 5;
	}else{
		sprite->currentFrame = 4;
	}
	int x = 0, y = 0, dx = 0;
	if(sprite->facing == LEFT){
		x = sprite->pos.x + 5;
		y = sprite->pos.y + 20;
	}else{
		x = sprite->pos.x + 35;
		y = sprite->pos.y + 20;
	}
	int direction = (sprite->facing == LEFT)? -STEP_SIZE : STEP_SIZE;
	dx = direction * 1.5;
	makeBullet(bullets, x, y, dx);
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Shooting.\n");
}

void updateBullets(List *bullets){
	if(list_size(bullets) > 0){
		ListElmt *elmt = list_head(bullets);
		for(elmt = list_head(bullets); elmt != NULL && list_size(bullets) > 0; elmt = list_next(elmt)){
			struct Bullet *nextBullet = list_data(elmt);
			nextBullet->pos = add(nextBullet->pos, nextBullet->vel);
			if(nextBullet->pos.x > WINDOW_W || nextBullet->pos.x < 0){
				list_rem(bullets, elmt, (void **)&nextBullet);
				SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
					    "Bullet disappeared. %d remaining.\n", list_size(bullets));
				if(nextBullet != NULL){
					free(nextBullet);
				}
			}
		}
	}
}

void playerUpdate(void *playerParam){
	/* Player update logic */
	struct GameWorld *world = (struct GameWorld*)playerParam;
	player = world->player;
	/* Update player using KEYBOARD */
	if(isKeyDown(SDL_SCANCODE_LEFT)){
		if(player->pos.x > 0){
			player->state = WALKING;
			struct Vec2d step = {-STEP_SIZE, 0};
			player->pos = add(player->pos, step);
			player->facing = LEFT;
			if(globalTime % 6 == 0){
				player->currentFrame++;
				player->currentFrame %= 4;
			}
		}
	}else if(isKeyDown(SDL_SCANCODE_RIGHT)){
		if(player->pos.x < world->level_w - STEP_SIZE - player->w){
			player->state = WALKING;
			struct Vec2d step = {STEP_SIZE, 0};
			player->pos = add(player->pos, step);
			player->facing = RIGHT;
			if(globalTime % 6 == 0){
				player->currentFrame++;
				player->currentFrame %= 4;
			}
		}
	}else{
		player->state = IDLE;
		player->currentFrame = 4;
	}
	
	if(isKeyDown(SDL_SCANCODE_UP) && player->state != JUMPING && collidingBelow(world->ledges, player)){
		player->state = JUMPING;
		player->vel.y = -30;
	}

	if(isKeyDown(SDL_SCANCODE_SPACE)){
		if(globalTime % 6 == 0){
			shoot(player);
		}
	}

	if(player->state == JUMPING){
		if(globalTime % 5 == 0){
			struct Vec2d diff = subtract(player->vel, gravity);
			player->vel = subtract(player->vel, gravity);
			player->pos = add(player->pos, diff);
		}
		if(player->vel.y <= 3){
			player->state = IDLE;
			player->vel.y = 10;
		}

	}
	
	if(player->state == JUMPING || collidingBelow(world->ledges, player)){
		/* do nothing */
	}else{
		player->pos = add(player->pos, player->vel);
	}
		
	

}

void drawBullets(List *bullets, SDL_Renderer *renderer){
	ListElmt *elmt;
	for(elmt = list_head(bullets); elmt != NULL; elmt = list_next(elmt)){
		struct Bullet *bullet = (struct Bullet *)list_data(elmt);
		DrawImage(bulletTexture, bullet->pos.x, bullet->pos.y, 8, 8, 0,
			  SDL_FLIP_NONE, renderer );
	}
}

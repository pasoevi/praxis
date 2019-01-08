#ifndef TEXTURE_H
#include "texture.h"
#endif

#ifndef GAMEWORLD_H
#include "gameworld.h"
#endif

#ifndef GEOMETRY_H
#include "geometry.h"
#endif
#include "sprite.h"

#define STEP_SIZE 6
#define PROXIMITY 300
#define COLLISION 2

extern int globalTime;

/* struct Sprite *enemy; */
struct Sprite *player;
int enemyLives = 3;

static Sint16 enemyRadius = 30;
static int enemyChasing = 0;
extern int WINDOW_W;
extern int WINDOW_H;
extern int LEVEL_W;
extern int LEVEL_H;

extern int playerLives;

void enemyUpdate(void *gameWorld){
	/* Enemy update logic */
	struct GameWorld *world = (struct GameWorld*) gameWorld;
	struct Sprite *enemy = world->enemy;
	player = world->player;
	/* Update enemy using KEYBOARD */
	if(enemy->pos.y < 0){
		enemy->vel.y = STEP_SIZE;
	}

	if(enemy->pos.y > WINDOW_H - enemy->h){
		enemy->vel.y = -STEP_SIZE;
	}

	enemy->pos = add(enemy->pos, enemy->vel);
	if(globalTime % 6 == 0){
		enemy->currentFrame++;
		enemy->currentFrame %= 2;
	}

	/* wrop around horizontally */
	if (enemy->pos.x - enemyRadius < 0 || enemy->pos.x + enemyRadius > LEVEL_W){
		enemy->vel.x = -enemy->vel.x;
	}

	/* wrop around vertically */
	if (enemy->pos.y - enemyRadius < 0 || enemy->pos.y + enemyRadius > LEVEL_H){
		enemy->vel.y = -enemy->vel.y;
	}

	/* The enemy needs to check if you're near */
	double distance = Vec2dLen(subtract(player->pos, enemy->pos));
	if (distance <= PROXIMITY + player->w / 2 + enemyRadius){
		if (!enemyChasing){
			enemyChasing = 1;
			if (player->pos.x > enemy->pos.x){
				enemy->vel.x = -enemy->vel.x;
			}
			if (player->pos.y > enemy->pos.y){
				enemy->vel.y = -enemy->vel.y;
			}
		}
	}
	else{
		enemyChasing = 0;
	}
	enemy->pos = add(enemy->pos, enemy->vel);

	/* Check collision */
	if (distance <= COLLISION + player->w / 2 + enemyRadius){
		/* enemyPos = (struct Vec2d){WINDOW_W / 2, WINDOW_H / 2}; */
		if(playerLives > 0){
			playerLives--;
			/* throw the player away from the enemy */
			player->pos = add(player->pos,
					  add(subtract(enemy->pos, player->pos),
					      (struct Vec2d){100, 0}));
		}else{
			/* toGameoverMode(fsm); */
		}
	}

}

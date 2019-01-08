#include "bullet.h"

void makeBullet(List *bullets, int x, int y, int dx){
	struct Bullet *bullet = malloc(sizeof(struct Bullet));
	bullet->pos.x = x;
	bullet->pos.y = y;
	bullet->vel.x = dx;
	bullet->vel.y = 0;

	list_ins_next(bullets, list_tail(bullets), bullet);
}

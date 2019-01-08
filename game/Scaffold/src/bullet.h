#ifndef GEOMETRY_H
#include "geometry.h"
#endif
#ifndef LIST_H
#include "list.h"
#endif

struct Bullet{
	struct Vec2d pos;
	struct Vec2d vel;
};

void makeBullet(List *bullets, int x, int y, int dx);

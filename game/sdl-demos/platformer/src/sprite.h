#ifndef SPRITE_H
#define SPRITE_H
#include "geometry.h"

struct Sprite{
        SDL_Rect body;
	struct Vec2d vel;
        int ammo;
        int score;
        int hp; /* health points */
        int damage;
	int lives;
        SDL_Color color;
        void (*update)(struct Sprite *sprite, void *world);
        void (*render)(struct Sprite *ship);
};
#endif

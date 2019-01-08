/*
 * File:   player.h
 * Author: sergi
 *
 * Created on December 31, 2014, 7:34 PM
 */

#ifndef SPRITE_H
#define	SPRITE_H

#ifndef GEOMETRY_H
#include "geometry.h"
#endif

#include <stdlib.h>
#ifndef TEXTURE_H
#include "texture.h"
#endif

#ifndef CAMERA_H
#include "camera.h"
#endif

/* Currently the sprite can be in only one of these conditions at a
   time. Visible is a separate state
*/

enum direction {
	LEFT,
	RIGHT
};

enum movement_state{
	IDLE,
	JUMPING,
	FALLING,
	WALKING,
	SHOOTING
};

struct Sprite{
	int w, h;
	int hitPoints;
	struct Vec2d pos, vel, accel;
	enum direction facing;
	void *texture;
	int numFrames;
	int currentFrame;
	enum movement_state state;
	int visible;
	int alive;
	void (*update)(void *world);
};

#define DEFAULT_HIT_POINTS 5

int makeSprite(struct Sprite *sprite, int numFrames, int hitPoints,
	       struct Vec2d pos, struct Vec2d vel);
void drawSprite(struct Sprite *sprite, struct Camera *camera,
		SDL_Renderer *renderer);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PLAYER_H */

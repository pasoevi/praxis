/*
  Copyright (C) 2015, 2016 Sergi Pasoev.

  This pragram is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or (at
  your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.

  Written by Sergi Pasoev <s.pasoev@gmail.com>
*/

#include <stdlib.h>
#include "bullet.h"
#include "keyboard.h"
#include "drawing.h"

/* Color modes */
#define COLOR_MODE_CYAN 0
#define COLOR_MODE_MULTI 1
extern int WINDOW_H;

int colorMode = COLOR_MODE_CYAN;
GLfloat projectionScale = 1.f;

/* extern struct GameWorld *world; */

extern void destroy(void* data);

List * initBullets(void){
        List *bullets = malloc(sizeof *bullets);
        list_init(bullets, destroy);
        return bullets;
}

void handleKeys(void);

void shoot(struct Sprite *sprite, struct GameWorld *world){
	int x = 0, y = 0, dx = 0, dy = 0, w = 0, h = 0, damage = 0, direction, offset;
        direction = sprite->vel.y > 0 ? 1 : -1;
	damage = sprite->damage / 10;
        w = h = damage * 5;
        x = sprite->body.x + sprite->body.w / 2 - 5;
        offset = direction * (sprite->body.h);
        y = sprite->body.y + offset;

        dy = direction * 19.5;
        sprite->ammo--;
	makeBullet(world->bullets, x, y, dx, dy, w, h, damage);
}

void makeBullet(List *bullets, int x, int y, int dx, int dy, int w, int h, int damage){
	SDL_Rect rect;
	SDL_Color color = {25, 52, 25, 255};
	struct Sprite *bullet = malloc(sizeof *bullet);
	struct Vec2d vel;
	vel.x = dx;
	vel.y = dy;
	
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
        
        bullet->body = rect;
        bullet->vel = vel;
        bullet->lives = 1;
        bullet->damage = 3;
        bullet->hp = 1;
        bullet->color = color;
        list_ins_next(bullets, list_tail(bullets), bullet);
}

void updateBullets(struct GameWorld *world){
	List *bullets = world->bullets;
	ListElmt *elmt = list_head(bullets);
	
	handleKeys();
	
	for(elmt = list_head(bullets); elmt != NULL; elmt = list_next(elmt)){
		struct Sprite *bullet = list_data(elmt);
		bullet->body.y += bullet->vel.y;
		if(bullet->body.y <= 0 || bullet->body.y >= WINDOW_H){
			list_rem(bullets, elmt);
			break;
		}
	}

        if(world->ship->ammo < 3){
                colorMode = COLOR_MODE_MULTI;
        }else{
                colorMode = COLOR_MODE_CYAN;
        }
}

void renderBullets(List *bullets){
        ListElmt *elmt = list_head(bullets);
        for(elmt = list_head(bullets); elmt != NULL; elmt = list_next(elmt)){
                struct Sprite *bullet = list_data(elmt);
                bulletRender(bullet);
        }
}

void bulletRender(struct Sprite *bullet){
        /* Render quad */
        if(colorMode == COLOR_MODE_CYAN){
                drawSprite(bullet);
        }else{
                glBegin(GL_QUADS);
                glColor3f( 1.f, 0.f, 0.f );
                glVertex2f(bullet->body.x, bullet->body.y);

                glColor3f( 1.f, 1.f, 0.f );
                glVertex2f(bullet->body.x, bullet->body.y + bullet->body.h);

                glColor3f( 0.f, 1.f, 0.f );
                glVertex2f(bullet->body.x + bullet->body.w, bullet->body.y + bullet->body.h);

                glColor3f( 0.f, 0.f, 1.f );
                glVertex2f(bullet->body.x + bullet->body.w, bullet->body.y);
                glEnd();
        }
}

void handleKeys(void){
        if(isKeyDown(SDL_SCANCODE_2)) {
                /* Toggle color mode */
                if( colorMode == COLOR_MODE_CYAN ) {
                        colorMode = COLOR_MODE_MULTI;
                }else{
                        colorMode = COLOR_MODE_CYAN; }
        }else if(isKeyDown(SDL_SCANCODE_1)){
                printf("s\n");
                /* Cycle through projection scales */
                if( projectionScale == 1.f ) {
                        /* Zoom out */
                        projectionScale = 2.f;
                } else if( projectionScale == 2.f ) {
                        /* Zoom in */
                        projectionScale = 0.5f;
                } else if( projectionScale == 0.5f ) {
                        /* Regular zoom */
                        projectionScale = 1.f;
                }
                /* Update projection matrix */
                glMatrixMode( GL_PROJECTION );
                glLoadIdentity();
                glOrtho( 0.0, 800 * projectionScale, 600 * projectionScale, 0.0, 1.0, -1.0 );
        }
}

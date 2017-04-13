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

#include "powerup.h"
#include "drawing.h"
#include "gameworld.h"
#include <stdlib.h>

extern int globalTime;
extern void destroy(void* data);

List* initPowerups(void){
        List *powerups = malloc(sizeof *powerups);
        list_init(powerups, destroy);
        return powerups;
}

void addPowerup(List *powerups, int x, int y, int dx, int dy, int w, int h,
              const char *texturefilename){
        struct Sprite *powerup = malloc(sizeof *powerup);
	struct Vec2d vel;
	SDL_Rect rect;
	SDL_Color color = {245, 55, 155, 255};
	
	vel.x = dx;
	vel.y = dy;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	
        powerup->body = rect;
        powerup->vel = vel;
        powerup->hp = 1;
        powerup->color = color;
        powerup->damage = 50;
        powerup->lives = 1;
        powerup->update = powerupUpdate;
        powerup->render = drawSprite;
        list_ins_next(powerups, list_tail(powerups), powerup);
}

void activatePowerup(struct Sprite *sprite, struct Sprite *powerup){
        sprite->damage += powerup->damage;
        sprite->hp += powerup->hp;
        sprite->lives += powerup->lives;
        sprite->ammo += powerup->ammo;
        sprite->color = powerup->color;
        sprite->vel = add(sprite->vel, multByScalar(powerup->vel, -1));
}

void powerupUpdate(struct Sprite *powerup, void *world){
        powerup->body.y += powerup->vel.y  + 1 / powerup->body.w;
}

void renderPowerups(List *powerups){
        ListElmt *elmt;
        for(elmt = list_head(powerups); elmt != NULL; elmt = list_next(elmt)){
                struct Sprite *powerup = list_data(elmt);
                powerup->render(powerup);
        }
}

void updatePowerups(void *worldParam){
        struct GameWorld *world = (struct GameWorld *)worldParam;
        ListElmt *elmt;
	
        for(elmt = list_head(world->powerups); elmt != NULL; elmt = list_next(elmt)){
                struct Sprite *powerup = list_data(elmt);
                powerup->update(powerup, worldParam);

                /* Delete enemies that reach the bottom of the screen */
                if(powerup->body.y > world->windowH){
                        list_rem(world->powerups, elmt);
			break;
                }
        }
}



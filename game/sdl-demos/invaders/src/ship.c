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

#include "ship.h"
#include "drawing.h"
#include "bullet.h"

enum {
        INITIAL_AMMO
};

extern int globalTime;
extern int WINDOW_W;
extern int WINDOW_H;
extern int FPS;

struct Sprite * initShip(void){
        struct Sprite *ship = malloc(sizeof *ship);
	SDL_Color color = {55, 55, 5, 255};
	int shipW = 50, shipH = 90;
	SDL_Rect rect;
	struct Vec2d vel;
	
	vel.x = STEP_SIZE;
	vel.y = -STEP_SIZE;
	
	rect.x = WINDOW_W / 2 - shipW /2;
	rect.y =  WINDOW_H - shipH;
	rect.w =  shipW;
	rect.h = shipH;
	
        ship->update = shipUpdate;
        ship->render = drawSprite;
        ship->hp = 15;
        ship->color = color;
        ship->lives = 3;
        ship->score = 0;
        ship->ammo = 2220;
	
        ship->body = rect;
        ship->vel = vel;
	ship->damage = 10;
        return ship;
}

void shipUpdate(struct Sprite *ship, void *worldParam){
        struct GameWorld *world = (struct GameWorld *)worldParam;
        if(isKeyDown(SDL_SCANCODE_LEFT)){
                int newX = world->ship->body.x - world->ship->vel.x;
                /* if the ship isn't going farther than the left edge */
                if(newX >= 0){
                        world->ship->body.x = newX;
                }else{
                        /* now move the ship to the left with a
			   shorter step than STEP_SIZE */
                        if(STEP_SIZE - abs(newX) > 0){
                                (world->ship->body.x) -= STEP_SIZE - abs(newX);
                        }
                }
        }
        if(isKeyDown(SDL_SCANCODE_RIGHT)){
                int newX = world->ship->body.x + world->ship->vel.x;
                if(newX + world->ship->body.w <= world->windowW){
                        world->ship->body.x = newX;
                }else{
                        /* now move ship to the right with a shorter step than STEP_SIZE */
                        int difference = abs((newX + world->ship->body.w) - world->windowW);
                        if(world->ship->body.x + world->ship->body.w + difference <= world->windowW){
                                (world->ship->body.x) += difference;
                        }
                }
        }
        if(isKeyDown(SDL_SCANCODE_UP)){
                int newY = world->ship->body.y + world->ship->vel.y;
                /* if the ship isn't going farther than the left edge */
                if(newY >= 0){
                        world->ship->body.y = newY;
                }else{
                        /* now move ship to the left with a shorter step than STEP_SIZE */
                        if(STEP_SIZE - abs(newY) > 0){
                                (world->ship->body.y) -= STEP_SIZE - abs(newY);
                        }
                }
        }
        if(isKeyDown(SDL_SCANCODE_DOWN)){
                int newY = world->ship->body.y - world->ship->vel.y;
                if(newY + world->ship->body.h <= world->windowH){
                        world->ship->body.y = newY;
                }else{
                        /* now move ship to the right with a shorter step than STEP_SIZE */
                        int difference = abs((newY + world->ship->body.w) - world->windowW);
                        if(world->ship->body.y + world->ship->body.h + difference <= world->windowH){
                                (world->ship->body.y) += difference;
                        }
                }
        }
        if(isKeyDown(SDL_SCANCODE_SPACE)){
                if(world->ship->ammo > 0){
                        if(globalTime % 5 == 0){
                                shoot(world->ship, world);
                        }
                }
        }
}

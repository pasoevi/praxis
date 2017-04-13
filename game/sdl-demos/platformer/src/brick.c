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

#include "brick.h"
#include "drawing.h"
#include <stdlib.h>

extern int globalTime;
extern void destroy(void* data);

List * initBricks(void){
        List *bricks = malloc(sizeof *bricks);
        list_init(bricks, destroy);
        return bricks;
}

void addBrick(List *bricks, int x, int y, int dx, int dy, int w, int h,
              const char *texturefilename){
        struct Sprite *brick = malloc(sizeof *brick);
        brick->body = (SDL_Rect){x, y, w, h};
        brick->vel = (struct Vec2d){dx, dy};
        brick->ammo = 5;
        brick->hp = 7;
        brick->color = (SDL_Color){55, 55, 255, 255};
        brick->damage = 50;
        brick->lives = 1;
        brick->update = brickUpdate;
        brick->render = drawSprite;
        list_ins_next(bricks, list_tail(bricks), brick);
}

void brickUpdate(struct Sprite *brick, void *world){
        brick->body.y += brick->vel.y  + 1 / brick->body.w;
        if(brick->ammo > 0){
                if(brick->body.y > 0 && globalTime % 30 == 0){
                        shoot(brick, (struct Gameworld *)world);
                }
        }
}

void renderBricks(List *bricks){
        ListElmt *elmt;
        for(elmt = list_head(bricks); elmt != NULL; elmt = list_next(elmt)){
                struct Sprite *brick = list_data(elmt);
                brick->render(brick);
        }
}

void updateBricks(struct GameWorld *world){

}

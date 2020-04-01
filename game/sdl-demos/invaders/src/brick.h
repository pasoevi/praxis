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

#ifndef BRICK_H
#define BRICK_H
#include <stdbool.h>
#include "gameworld.h"
#include "list.h"
#include "drawing.h"
#include "sprite.h"

List * initBricks(void);
void addBrick(List *bricks, int x, int y, int dx, int dy, int w, int h,
              const char *texturefilename);

void brickUpdate(struct Sprite *brick, void *world);
void brickRender(struct Sprite *brick);
void destroyBrick(void *);

void updateBricks(void *worldParam);
void renderBricks(List *bricks);
#endif

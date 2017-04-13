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

#ifndef SHIP_H
#define SHIP_H
#include <math.h>
#include <SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "keyboard.h"
#include "gameworld.h"
#include "sprite.h"

enum {
        STEP_SIZE = 10
};

struct Sprite * initShip(void);
void shipUpdate(struct Sprite *ship, void *worldParam);
void shipRender(struct Sprite *ship);


#endif

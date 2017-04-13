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

#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include <stdio.h>
#ifndef GAMESTATE_H
#include "gamestate.h"
#endif
#ifndef GEOMETRY_H
#include "geometry.h"
#endif
/* #include "brick.h" */
#include "ship.h"

struct GameWorld {
        int level;
        int maxLevel;
        struct Sprite *ship;
        List *bullets;
        List *bricks;
        List *powerups;
        int lives;
        int windowW;
        int windowH;
        void (*update)(void *world);
};

#endif

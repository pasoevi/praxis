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

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "bullet.h"
#include "brick.h"
#include "list.h"

/* bool colliding(struct Sprite *bullet, struct Sprite *brick); */
/* Handle collisions: Updates bullet and bricks! */
int handleBulletBrickCollisions(List *bullets, List *bricks);
void handleShipEnemyCollisions(struct Sprite *ship, List *enemies);
void handleShipPowerupCollisions(struct Sprite *ship, List *powerups);

/*

  Copyright (C) 2013, 2014 Sergi Pasoev.

  This pragram is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.

  Written by Sergi Pasoev <s.pasoev@gmail.com>
*/

#include "collision.h"

/* is_collision: take the bounding boxes for two
   objects and return 1 if they collide */
int is_collision(Box *a, Box *b){
    if ((a->pos.x > b->pos.x + b->width - 1.0f) || // is b1 on the right side of b2?
        (a->pos.y > b->pos.y + b->height - 1.0f) || // is b1 under b2?
        (b->pos.x > a->pos.x + a->width - 1.0f) || // is b2 on the right side of b1?
        (b->pos.y > a->pos.y + a->height - 1.0f))   // is b2 under b1?
    {
        // no collision
        return 0;
    }
 
    // collision
    return 1;
}

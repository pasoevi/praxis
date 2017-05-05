/*

  Copyright (C) 2013 Sergi Pasoev.

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

/* A spaceship */

#include "blasteroids.h"
  
Spaceship* init_ship(void){
  static Spaceship ship;
  ship.sx = ORIGIN_X;
  ship.sy = ORIGIN_Y;
  ship.heading = -90.0f;
  ship.speed = 0.0001;
  ship.gone = 0;
  ship.color = al_map_rgb(0, 255, 0);

  return &ship;
}

float head2theta(float heading){
  return (heading)/360*6.25;
}

void draw_ship(Spaceship *ship){
  ALLEGRO_TRANSFORM transform;

  if(al_get_current_transform() == NULL)
    fprintf(stderr, "no target bitmap.");
  
  al_identity_transform(&transform);
  al_rotate_transform(&transform, 1.58525 + head2theta(ship->heading));
  al_translate_transform(&transform, ship->sx, ship->sy);
  al_use_transform(&transform);
  
  al_draw_line(-8, +9, 0, -11, ship->color, 3.0f);
  al_draw_line(0, -11, 8, 9, ship->color, 3.0f);
  al_draw_line(-6, 4, 1, 4, ship->color, 3.0f);
  al_draw_line(6, 4, 1, 4, ship->color, 3.0f);

  
}

void fly_ship(Spaceship* ship){
  /* increments sx and sy values depending on whence
     the ship is heading*/
  float theta = head2theta(ship->heading);

  // if the ship is still inside the screen
  if(ship->sx > 0 && ship->sx <= SCREEN_W){
    ship->sx += ship->speed * cos(theta);
  }else{
    if(ship->sx < 0){
      (ship->sx)++;
    }else{
      (ship->sx)--;
    }
  }
  
  if(ship->sy > 0 &&ship->sy <= SCREEN_H){
    ship->sy += ship->speed * sin(theta);
  }else{
    if(ship->sy < 0){
      (ship->sy)++;
    }else
      (ship->sy)--;
  }
}

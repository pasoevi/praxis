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

Blast *init_blast(float x, float y, float heading){
  static Blast blast;

  blast.sx = x;
  blast.sy = y;
  blast.heading = heading;
  blast.speed = 25;
  blast.gone = 1;
  blast.color = al_map_rgb(255, 0, 0);

  return &blast;
}
  
void draw_blast(Blast *blast){
  ALLEGRO_TRANSFORM transform;

  if(al_get_current_transform() == NULL){
    fprintf(stderr, "no target bitmap.");
  }

  al_identity_transform(&transform);
  al_rotate_transform(&transform, 1.58525 + head2theta(blast->heading));
  al_translate_transform(&transform, blast->sx, blast->sy);
  al_use_transform(&transform);

  /* many small lines will eventually create a dashed line */
  al_draw_line(0, 0, 0, -10, blast->color, 3.0f);
  al_draw_line(0, -15, 0, -25, blast->color, 3.0f);
  al_draw_line(0, -30, 0, -40, blast->color, 3.0f);
  al_draw_line(0, -45, 0, -60, blast->color, 3.0f);
  al_draw_line(0, -65, 0, -80, blast->color, 3.0f);
  al_draw_line(0, -85, 0, -100, blast->color, 3.0f);
  al_draw_line(0, -105, 0, -120, blast->color, 3.0f);
}

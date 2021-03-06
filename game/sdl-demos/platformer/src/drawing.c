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

#include "drawing.h"

void drawRectangle(SDL_Rect rect, SDL_Color color){
        glBegin(GL_QUADS);
        glColor3ub( color.r, color.g, color.b);
        glVertex2f(rect.x, rect.y);
        glVertex2f(rect.x, rect.y + rect.h);
        glVertex2f(rect.x + rect.w, rect.y + rect.h);
        glVertex2f(rect.x + rect.w, rect.y);
        glEnd();
}

void drawSprite(struct Sprite *sprite){
        drawRectangle(sprite->body, sprite->color);
}

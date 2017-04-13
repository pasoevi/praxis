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

#include "geometry.h"

struct Vec2d add(struct Vec2d v1, struct Vec2d v2) {
        struct Vec2d vs;
        vs.x = v1.x + v2.x;
        vs.y = v1.y + v2.y;
        return vs;
}

struct Vec2d subtract(struct Vec2d v1, struct Vec2d v2) {
        struct Vec2d vs;
        vs.x = v1.x - v2.x;
        vs.y = v1.y - v2.y;
        return vs;
}

struct Vec2d multByScalar(struct Vec2d v, int scalar) {
        v.x *= scalar;
        v.y *= scalar;
        return v;
}

struct Vec2d divideByScalar(struct Vec2d v, int scalar) {
        v.x /= scalar;
        v.y /= scalar;
        return v;
}

struct Vec2d normalize(struct Vec2d v) {
        double l = Vec2dLen(v);
        if (l > 1) {
                int inverse = 1 / l;
                struct Vec2d norm;
                norm = multByScalar(v, inverse);
                return norm;
        }
        return v;
}

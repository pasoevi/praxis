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

#ifndef GEOMETRY_H
#define	GEOMETRY_H
#include <math.h>
#include <stdlib.h>

struct Vec2d{
        int x, y;
};

#define Vec2dLen(v) (sqrt(v.x * v.x + v.y * v.y))

struct Vec2d add(struct Vec2d v1, struct Vec2d v2);
struct Vec2d multByScalar(struct Vec2d v, int scalar);
struct Vec2d subtract(struct Vec2d v1, struct Vec2d v2);
struct Vec2d divideByScalar(struct Vec2d v, int scalar);
struct Vec2d normalize(struct Vec2d v);



#ifdef  __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* GEOMETRY_H */

/* 
 * File:   geometry.h
 * Author: sergi
 *
 * Created on December 31, 2014, 6:44 PM
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



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* GEOMETRY_H */

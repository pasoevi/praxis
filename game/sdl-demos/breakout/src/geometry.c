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

#include "drawing.h"

void drawRectangle(struct Vec2d pos, int w, int h){
	glBegin(GL_QUADS);
	glColor3f( 1.f, 1.f, 1.f );
	glVertex2f(pos.x, pos.y);
	glVertex2f(pos.x, pos.y + h);
	glVertex2f(pos.x + w, pos.y + h);
	glVertex2f(pos.x + w, pos.y);
	glEnd();
}

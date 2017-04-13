#include "ball.h"
#include "keyboard.h"

/* Color modes */
#define COLOR_MODE_CYAN 0
#define COLOR_MODE_MULTI 1


int colorMode = COLOR_MODE_CYAN;
GLfloat projectionScale = 1.f;

extern struct GameWorld *world;

void handleKeys(void);

void ballUpdate(void *worldParam){
	handleKeys();
	
	struct GameWorld *world = (struct GameWorld *)worldParam;
	world->ball->pos = add(world->ball->pos, world->ball->vel);
	struct Ball *ball = world->ball;
	struct Paddle *paddle = world->paddle;

	if(ball->pos.x >= world->window_w || ball->pos.x <= 0){
		ball->vel.x = -1 * ball->vel.x;
	}

	if(ball->pos.y <= 0){
		ball->vel.y = -1 * ball->vel.y;
	}

	if(ball->pos.y >= paddle->pos.y){
		if(ball->pos.x >= paddle->pos.x && ball->pos.x + ball->w <= paddle->pos.x + paddle->w){
			ball->vel.y = -1 * ball->vel.y;
		}else{
			sleep(1);
			ball->pos = (struct Vec2d){world->window_w / 2 - ball->w / 2, world->window_h / 2 - ball->h / 2};
			ball->vel.y = -1 * ball->vel.y;
			ball->vel.x = -1 * ball->vel.x;
			SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Died\n");
		}
	}
}
void ballRender(struct Ball *ball){
	/* Render quad */
	if(colorMode == COLOR_MODE_CYAN){
		glBegin(GL_QUADS);
		glColor3f( 0.f, 1.f, 1.f );
		glVertex2f(ball->pos.x, ball->pos.y);
		glVertex2f(ball->pos.x, ball->pos.y + ball->h);
		glVertex2f(ball->pos.x + ball->w, ball->pos.y + ball->h);
		glVertex2f(ball->pos.x + ball->w, ball->pos.y);
		glEnd();
	}else{
		glBegin(GL_QUADS);
		glColor3f( 1.f, 0.f, 0.f );
		glVertex2f(ball->pos.x, ball->pos.y);
		 
		glColor3f( 1.f, 1.f, 0.f );
		glVertex2f(ball->pos.x, ball->pos.y + ball->h);
		 
		glColor3f( 0.f, 1.f, 0.f );
		glVertex2f(ball->pos.x + ball->w, ball->pos.y + ball->h);
		 
		glColor3f( 0.f, 0.f, 1.f );
		glVertex2f(ball->pos.x + ball->w, ball->pos.y);
		glEnd();
	}
}

void handleKeys(void){
	if(isKeyDown(SDL_SCANCODE_ESCAPE)) {
		/* Toggle color mode */
		if( colorMode == COLOR_MODE_CYAN ) {
			colorMode = COLOR_MODE_MULTI;
		}else{
			colorMode = COLOR_MODE_CYAN; }
	}else if(isKeyDown(SDL_SCANCODE_1)){
		printf("s\n");

		/* Cycle through projection scales */
		if( projectionScale == 1.f ) {
			/* Zoom out */
			projectionScale = 2.f;
		} else if( projectionScale == 2.f ) {
			/* Zoom in */
			projectionScale = 0.5f;
		} else if( projectionScale == 0.5f ) {
			/* Regular zoom */
			projectionScale = 1.f;
		}
		/* Update projection matrix */
		glMatrixMode( GL_PROJECTION );
		glLoadIdentity();
		glOrtho( 0.0, 800 * projectionScale, 600 * projectionScale, 0.0, 1.0, -1.0 );
	}
}

#include <stdlib.h>
#include "bullet.h"
#include "keyboard.h"

/* Color modes */
#define COLOR_MODE_CYAN 0
#define COLOR_MODE_MULTI 1
extern int WINDOW_H;

int colorMode = COLOR_MODE_CYAN;
GLfloat projectionScale = 1.f;

extern struct GameWorld *world;

extern void destroy(void* data);

List * initBullets(void){
        List *bullets = malloc(sizeof *bullets);
        list_init(bullets, destroy);
        return bullets;
}

void handleKeys(struct GameWorld *world);

void shoot(struct Sprite *sprite, struct GameWorld *world){
        int x = 0, y = 0, dx = 0, dy = 0, w = 0, h = 0, direction, offset;
        direction = sprite->vel.y > 0 ? 1 : -1;
        w = h = sprite->body.w / 10;
        x = sprite->body.x + sprite->body.w / 2 - 5;
        offset = direction * (sprite->body.h);
        y = sprite->body.y + offset;

        dy = direction * 19.5;
        sprite->ammo--;
        makeBullet(world->bullets, x, y, dx, dy, w, h);
}

void makeBullet(List *bullets, int x, int y, int dx, int dy, int w, int h){
        struct Sprite *bullet = malloc(sizeof *bullet);
        bullet->body = (SDL_Rect){x, y, 10, 10};
        bullet->vel = (struct Vec2d){dx, dy};
        bullet->lives = 1;
        bullet->damage = 1;
        bullet->hp = 1;
        bullet->color = (SDL_Color){25, 52, 25, 255};
        list_ins_next(bullets, list_tail(bullets), bullet);
}

void updateBullets(struct GameWorld *world){

}

void renderBullets(List *bullets){
        if(list_size(bullets) > 0){
                ListElmt *elmt = list_head(bullets);
                for(elmt = list_head(bullets); elmt != NULL && list_size(bullets) > 0; elmt = list_next(elmt)){
                        struct Sprite *bullet = list_data(elmt);
                        bulletRender(bullet);
                }
        }
}

void bulletRender(struct Sprite *bullet){
        /* Render quad */
        if(colorMode == COLOR_MODE_CYAN){
                drawRectangle(bullet->body,
                              bullet->color);
        }else{
                glBegin(GL_QUADS);
                glColor3f( 1.f, 0.f, 0.f );
                glVertex2f(bullet->body.x,
                           bullet->body.y);

                glColor3f( 1.f, 1.f, 0.f );
                glVertex2f(bullet->body.x,
                           bullet->body.y + bullet->body.h);

                glColor3f( 0.f, 1.f, 0.f );
                glVertex2f(bullet->body.x + bullet->body.w,
                           bullet->body.y + bullet->body.h);

                glColor3f( 0.f, 0.f, 1.f );
                glVertex2f(bullet->body.x + bullet->body.w,
                           bullet->body.y);
                glEnd();
        }
}

void handleKeys(struct GameWorld *world){
        if(isKeyDown(SDL_SCANCODE_2)) {
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
                glOrtho(0.0, world->windowW * projectionScale,
                        world->windowH * projectionScale, 0.0, 1.0, -1.0 );
        }else if(isKeyDown(SDL_SCANCODE_W)){
                world->cameraY -= 16.f;
        }else if(isKeyDown(SDL_SCANCODE_S)){
                world->cameraY += 16.f;
        }else if(isKeyDown(SDL_SCANCODE_A)){
                world->cameraX -= 16.f;
        }else if(isKeyDown(SDL_SCANCODE_D)){
                world->cameraX += 16.f;
        }

        /* Take saved matrix off the stack and reset it */
        glMatrixMode( GL_MODELVIEW );
        glPopMatrix();
        glLoadIdentity();

        /* Move camera to position */
        glTranslatef( -world->cameraX, -world->cameraY, 0.f );

        /* Save default matrix again with camera translation */
        glPushMatrix();
}

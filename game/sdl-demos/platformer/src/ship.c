#include "ship.h"
#include "drawing.h"
#include "bullet.h"

enum {
        INITIAL_AMMO
};

extern int globalTime;
extern int WINDOW_W;
extern int WINDOW_H;
extern int FPS;

struct Sprite * initShip(void){
        struct Sprite *ship = malloc(sizeof *ship);
        ship->update = shipUpdate;
        ship->render = drawSprite;
        ship->hp = 15;
        ship->color = (SDL_Color){55, 55, 5, 255};
        ship->lives = 3;
        ship->score = 0;
        ship->ammo = 2220;
        int shipW, shipH;
        shipW = 50;
        shipH = 90;
        ship->body = (SDL_Rect){WINDOW_W / 2 - shipW /2, WINDOW_H - shipH, shipW, shipH};
        ship->vel = (struct Vec2d){STEP_SIZE, -STEP_SIZE};
        return ship;
}

void shipUpdate(struct Sprite *ship, void *worldParam){
        struct GameWorld *world = (struct GameWorld *)worldParam;
        if(isKeyDown(SDL_SCANCODE_LEFT)){
                int newX = ship->body.x - ship->vel.x;
                /* if the ship isn't going farther than the left edge */
                if(newX >= 0){
                        ship->body.x = newX;
                }else{
                        /* now move ship to the left with a shorter step than STEP_SIZE */
                        if(STEP_SIZE - abs(newX) > 0){
                                (ship->body.x) -= STEP_SIZE - abs(newX);
                        }
                }
                /* Update camera */
                world->cameraX -= STEP_SIZE;
        }
        if(isKeyDown(SDL_SCANCODE_RIGHT)){
                int newX = ship->body.x + ship->vel.x;
                if(newX + ship->body.w <= world->worldW){
                        ship->body.x = newX;
                }else{
                        /* now move ship to the right with a shorter step than STEP_SIZE */
                        int difference = abs((newX + ship->body.w) - world->windowW);
                        if(ship->body.x + ship->body.w + difference <= world->windowW){
                                (ship->body.x) += difference;
                        }
                }

                /* Move camera */
                world->cameraX += STEP_SIZE;
        }
        if(isKeyDown(SDL_SCANCODE_UP)){
                int newY = ship->body.y + ship->vel.y;
                /* if the ship isn't going farther than the left edge */
                if(newY >= 0){
                        ship->body.y = newY;
                }else{
                        /* now move ship to the left with a shorter step than STEP_SIZE */
                        if(STEP_SIZE - abs(newY) > 0){
                                (ship->body.y) -= STEP_SIZE - abs(newY);
                        }
                }
        }
        if(isKeyDown(SDL_SCANCODE_DOWN)){
                int newY = ship->body.y - ship->vel.y;
                if(newY + ship->body.h <= world->windowH){
                        ship->body.y = newY;
                }else{
                        /* now move ship to the right with a shorter step than STEP_SIZE */
                        int difference = abs((newY + ship->body.w) - world->windowW);
                        if(ship->body.y + ship->body.h + difference <= world->windowH){
                                (ship->body.y) += difference;
                        }
                }
        }
        if(isKeyDown(SDL_SCANCODE_SPACE)){
                if(world->ship->ammo > 0){
                        if(globalTime % 5 == 0){
                                shoot(ship, world);
                        }
                }
        }
}

void shipRender(struct Sprite *ship){
        /* Render quad */
        drawRectangle(ship->body, ship->color);
}

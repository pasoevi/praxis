#include <SDL2/SDL.h>
#include "list.h"

#define STEP_SIZE 6
void initPlayer(void);
void playerUpdate(void *playerParam);
/* void shoot(int x, int y, int dx); */
void drawBullets(List *bullets, SDL_Renderer *renderer);

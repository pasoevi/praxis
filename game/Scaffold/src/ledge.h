#ifndef TEXTURE_H
#include "texture.h"
#endif
#ifndef LIST_H
#include "list.h"
#endif

struct Ledge{
	int x;
	int y;
	int w;
	int h;
	SDL_Texture *texture;
};

void destroyLedge(void *data);
void initLedges(List *ledges, SDL_Renderer *renderer);
void renderLedges(List *ledges, int n, SDL_Renderer *renderer);



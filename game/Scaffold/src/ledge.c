#include "ledge.h"
#include "parselvl.h"

SDL_Texture *brickTexture;

void addLedge(List *ledges, int x, int y, int w, int h,
	      const char *texturefilename, SDL_Renderer *renderer){
	struct Ledge *ledge = malloc(sizeof (struct Ledge));
	ledge->x = x;
	ledge->y = y;
	ledge->w = w;
	ledge->h = h;
	ledge->texture = brickTexture;
	list_ins_next(ledges, list_tail(ledges), ledge);
}

void destroyLedge(void *data){
	struct Ledge *ledge = (struct Ledge*)data;
	SDL_DestroyTexture(ledge->texture);
}

List *ledges;
void initLedges(List *ledges, SDL_Renderer *renderer){
	/* LoadImage(textureFilename, &((*ledge)->texture), renderer); */

	int numLedges = 0;
	numLedges = parseLedges(ledges, "levels/objects.xml", addLedge);
	SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
		     "Loaded game objects: %d\n", numLedges);
}

void renderLedges(List *ledges, int n, SDL_Renderer *renderer){
	ListElmt *elmt;
	for(elmt = list_head(ledges); elmt != NULL; elmt = list_next(elmt)){
		struct Ledge *ledge = (struct Ledge *)list_data(elmt);
		DrawImage(ledge->texture, ledge->x, ledge->y, ledge->w,
			  ledge->h, 0, SDL_FLIP_NONE, renderer);
	}
}

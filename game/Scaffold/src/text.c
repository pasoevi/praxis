#include "text.h"

void DrawText(SDL_Renderer *renderer, char* string, int x, int y,
	      TTF_Font* font, Uint8 r, Uint8 g, Uint8 b) {
	SDL_Surface* renderedText = NULL;

	SDL_Color color;

	color.r = r;
	color.g = g;
	color.b = b;

	renderedText = TTF_RenderText_Solid(font, string, color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, renderedText);
	/* DrawTexture(SplashImage, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, renderer); */
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	DrawImage(texture, x, y, w, h, 0, SDL_FLIP_NONE, renderer);
	SDL_FreeSurface(renderedText);
}

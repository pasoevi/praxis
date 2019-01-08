#ifndef _TEXTURE_H

#include <SDL2/SDL.h>
int LoadImage(const char* filename,
	      SDL_Texture** texture, SDL_Renderer* renderer);
void DrawImage(SDL_Texture* texture, int x, int y, int width, int height,
	       double angle, SDL_RendererFlip flip, SDL_Renderer *renderer);
void DrawImageOnCamera(SDL_Texture* texture, SDL_Rect body, SDL_Rect* clip,
                       double angle, SDL_Point* center,
                       SDL_RendererFlip flip, SDL_Renderer *renderer);
void DrawImageFrame(SDL_Texture* texture, int x, int y, int width, int height,
		    int currentRow, int currentFrame, double angle,
		    SDL_RendererFlip flip, SDL_Renderer *renderer);
#endif
void DrawImageFrameOnCamera(SDL_Texture* texture, SDL_Rect body, SDL_Rect* clip,
			    int currentRow, int currentFrame,
			    double angle, SDL_Point* center,
			    SDL_RendererFlip flip, SDL_Renderer *renderer);

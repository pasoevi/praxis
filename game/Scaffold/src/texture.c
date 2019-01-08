#include "texture.h"
#include <SDL2/SDL_image.h>
#include <stdio.h>

int LoadImage(const char* filename,
	      SDL_Texture** texture, SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load(filename);
	if (tmpSurface == 0) {
		perror(SDL_GetError());
		return -1;
	}
	*texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	/* SDL_QueryTexture(texture, NULL, NULL, &sourceRectangle.w,
	   &sourceRectangle.h);*/
	SDL_FreeSurface(tmpSurface);
	if (texture != 0) {
		return 1;
	}
	return -1;
}

void DrawImage(SDL_Texture* texture, int x, int y, int width, int height,
	       double angle, SDL_RendererFlip flip, SDL_Renderer *renderer) {
	SDL_Rect srcRect;
	SDL_Rect destRect;

	if (flip == 0) {
		flip = SDL_FLIP_NONE;
	}

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, angle, NULL, flip);
	/* SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle,
	   center, flip ); */
}

void DrawImageOnCamera(SDL_Texture* texture, SDL_Rect body, SDL_Rect* clip,
		       double angle, SDL_Point* center,
		       SDL_RendererFlip flip, SDL_Renderer *renderer){
	/* Set rendering space and render to screen */
	SDL_Rect renderQuad = { body.x, body.y, body.w, body.h };

	/* Set clip rendering dimensions */
	if( clip != NULL )
		{
			renderQuad.w = clip->w;
			renderQuad.h = clip->h;
		}

	/* Render to screen */
	SDL_RenderCopyEx( renderer, texture, clip, &renderQuad, angle, center, flip );
}

void DrawImageFrame(SDL_Texture* texture, int x, int y, int width, int height,
		    int currentRow, int currentFrame, double angle,
		    SDL_RendererFlip flip, SDL_Renderer* renderer) {
	SDL_Rect srcRect;
	SDL_Rect destRect;

	if (flip == 0) {
		flip = SDL_FLIP_NONE;
	}


	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, angle, 0, flip);
}

/*
  void DrawImageFrameOnCamera(SDL_Texture* texture, SDL_Rect body,
  SDL_Rect* clip,
  int currentRow, int currentFrame,
  double angle, SDL_Point* center,
  SDL_RendererFlip flip, SDL_Renderer *renderer){
  SDL_Rect srcRect;
  // Set rendering space and render to screen
  SDL_Rect renderQuad = { body.x, body.y, body.w, body.h };

  // Set clip rendering dimensions
  if( clip != NULL )
  {
  renderQuad.w = clip->w;
  renderQuad.h = clip->h;
  }
  srcRect.x = body.w * currentFrame;
  srcRect.y = body.h * (currentRow - 1);
  srcRect.w = renderQuad.w = body.w;
  srcRect.h = renderQuad.h = body.h;

  //Render to screen
  SDL_RenderCopyEx( renderer, texture, clip, &renderQuad, angle, center, flip);
  }
*/

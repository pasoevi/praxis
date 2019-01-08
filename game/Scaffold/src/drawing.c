#include "drawing.h"

void Gradient(SDL_Surface *Screen, SDL_Color Color,
	      int StartX, int StartY, int EndX, int EndY) {
	Uint8 R, G, B;
	int X;
	for(X = StartX; X < (StartX + EndX); X++) {
		int Y;
		for(Y = StartY; Y < (StartY + EndY); Y++) {
			R = (Color.r * ((StartX + EndX + StartY + EndY) - (Y + X)) /
			     (StartX + EndX + StartY + EndY));
			G = (Color.g * ((StartX + EndX + StartY + EndY) - (Y + X)) /
			     (StartX + EndX + StartY + EndY));
			B = (Color.b * ((StartX + EndX + StartY + EndY) - (Y + X)) /
			     (StartX + EndX + StartY + EndY));

			Uint32 PixelColor = SDL_MapRGB(Screen->format, R, G, B);

			Uint32 *Bufp;
			Bufp = (Uint32 *)Screen->pixels + Y * Screen->pitch/4 + X;
			*Bufp = PixelColor;
		}
	}
}

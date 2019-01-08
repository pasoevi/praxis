/*
 * File:   scaffold.h
 * Author: sergi
 *
 * Created on December 25, 2014, 3:34 PM
 */

#ifndef SCAFFOLD_H
#define	SCAFFOLD_H

#include <SDL2/SDL.h>
int init(SDL_Window **window, SDL_Renderer **renderer);
void processEvents(void);
void destroy(void*);
void quit(SDL_Window *window, SDL_Renderer *renderer);
void queryResolution(int *x, int *y);
#include "gamestate.h"
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SCAFFOLD_H */

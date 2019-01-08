#include <stdio.h>
#include <string.h>
/*
  #include <libxml2/libxml/parser.h>
  #include <libxml2/libxml/tree.h>
*/
#include "yxml.h"
#ifndef SDL_H
#include <SDL2/SDL.h>
#endif
#ifndef LIST_H
#include "list.h"
#endif

int parseLedges(List *ledges, char *filename,
		void (*addLedge)(List *ledges,
				 int x, int y, int w, int h,
				 const char *texturefilename,
				 SDL_Renderer *renderer));

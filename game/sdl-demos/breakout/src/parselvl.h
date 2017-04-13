#include <stdio.h>
#include <stdlib.h>
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

int parseBricks(List *bricks, char *filename,
		void (*addBrick)(List *bricks,
				 int x, int y, int w, int h,
				 const char *texturefilename));

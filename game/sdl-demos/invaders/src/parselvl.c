/*
  Copyright (C) 2015, 2016 Sergi Pasoev.

  This pragram is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or (at
  your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.

  Written by Sergi Pasoev <s.pasoev@gmail.com>
*/

#include "parselvl.h"
#include "brick.h"
#include "powerup.h"
#include "gameworld.h"
#include <stdlib.h>
#include <stddef.h>
#define BUFSIZE 4096

static char stack[8*1024];
static int verbose = 0;

char pos_xChr[20] = "", pos_yChr[20] = "";
char vel_xChr[20] = "", vel_yChr[20] = "";
char wChr[20] = "", hChr[20] = "", textureFilenameChr[128] = "";
char objTypeChr[20] = "";
int pos_x = 0, pos_y = 0, vel_x = 0, vel_y = 0, w = 0, h = 0;
char textureFilename[128] = "";
char objType[20] = "";

static void y_printres(yxml_t *x, yxml_ret_t r, struct GameWorld *world) {
        static int indata;
        int nextdata = 0;

        switch(r) {
        case YXML_OK:
                if(verbose) {
                        /* y_printtoken(x, "ok"); */
                        nextdata = 0;
                } else
                        nextdata = indata;
                break;
        case YXML_ELEMSTART:
                break;
        case YXML_ELEMEND:
                if(!strcmp(objType, "alien_ship")){
                        addBrick(world->bricks, pos_x, pos_y, vel_x, vel_y, w, h, textureFilename);
                }else if(!strcmp(objType, "powerup")){
                        addPowerup(world->powerups, pos_x, pos_y, vel_x, vel_y, w, h, textureFilename);
                }

                break;
        case YXML_ATTREND:
                if(!strcmp("type", x->attr)){
                        strcpy(objType, objTypeChr);
                        memset(objTypeChr, 0, sizeof(objTypeChr));
                }else if(!strcmp("x", x->attr)){
                        pos_x = atoi(pos_xChr);
                        memset(pos_xChr, 0, sizeof(pos_xChr));
                }else if(!strcmp("y", x->attr)){
                        pos_y = atoi(pos_yChr);
                        memset(pos_yChr, 0, sizeof(pos_yChr));
                }else if(!strcmp("dx", x->attr)){
                        vel_x = atoi(vel_xChr);
                        memset(vel_xChr, 0, sizeof(vel_xChr));
                }else if(!strcmp("dy", x->attr)){
                        vel_y = atoi(vel_yChr);
                        memset(vel_yChr, 0, sizeof(vel_yChr));
                }else if(!strcmp("width", x->attr)){
                        w = atoi(wChr);
                        memset(wChr, 0, sizeof(wChr));
                }else if(!strcmp("height", x->attr)){
                        h = atoi(hChr);
                        memset(hChr, 0, sizeof(hChr));
                }else if(!strcmp("textureFile", x->attr)){
                        strcpy(textureFilename, textureFilenameChr);
                        memset(textureFilenameChr, 0, sizeof(textureFilenameChr));
                }
                break;
        case YXML_PICONTENT:
        case YXML_CONTENT:
        case YXML_ATTRVAL:
                if(!strcmp("type", x->attr)){
                        strcat(objTypeChr, x->data);
                }else if(!strcmp("x", x->attr)){
                        strcat(pos_xChr, x->data);
                }else if(!strcmp("y", x->attr)){
                        strcat(pos_yChr, x->data);
                }else if(!strcmp("dx", x->attr)){
                        strcat(vel_xChr, x->data);
                }else if(!strcmp("dy", x->attr)){
                        strcat(vel_yChr, x->data);
                }else if(!strcmp("width", x->attr)){
                        strcat(wChr, x->data);
                }else if(!strcmp("height", x->attr)){
                        strcat(hChr, x->data);
                }else if(!strcmp("textureFile", x->attr)){
                        strcat(textureFilenameChr, x->data);
                }
                nextdata = 1;
                break;
        case YXML_PISTART:
                break;
        case YXML_PIEND:
                break;
                /* default:*/
                /* exit(0); */
                /* printf("Something unexpected happened."); */
        }
        indata = nextdata;
}

void parseLevel(struct GameWorld *world, const char *filename){
	FILE *fp;
        long lSize;
	
        int c;
        yxml_ret_t r;
        yxml_t x[1];
        yxml_init(x, stack, sizeof(stack));
	
        
        fp = fopen (  filename , "rb" );
        if( !fp ) perror(filename),exit(1);

        fseek( fp , 0L , SEEK_END);
        lSize = ftell( fp );
        rewind( fp );

        while((c = getc(fp)) != EOF) {
                r = yxml_parse(x, c);
                y_printres(x, r, world);
        }

        fclose(fp);
}

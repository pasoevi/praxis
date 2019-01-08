#include "parselvl.h"
#include "ledge.h"
#define BUFSIZE 4096

static char stack[8*1024];
static int verbose = 0;

char pos_xChr[20] = "", pos_yChr[20] = "";
char wChr[20] = "", hChr[20] = "", textureFilenameChr[128] = "";
int pos_x = 0, pos_y = 0, w = 0, h = 0;
char textureFilename[128] = "";

static void y_printres(yxml_t *x, yxml_ret_t r, List *ledges) {
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
		addLedge(ledges, pos_x, pos_y, w, h, "graphics/bricks.png", NULL);
		break;
	case YXML_ATTREND:
		if(!strcmp("x", x->attr)){
			pos_x = atoi(pos_xChr);
			memset(pos_xChr, 0, sizeof(pos_xChr));
		}else if(!strcmp("y", x->attr)){
			pos_y = atoi(pos_yChr);
			memset(pos_yChr, 0, sizeof(pos_yChr));
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
		if(!strcmp("x", x->attr)){
			strcat(pos_xChr, x->data);
		}else if(!strcmp("y", x->attr)){
			strcat(pos_yChr, x->data);
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

int parseLedges(List *ledges, char *filename,
		void (*addLedge)(List *ledges,
				 int x, int y, int w, int h,
				 const char *texturefilename,
				 SDL_Renderer *renderer)){
	int c;
	yxml_ret_t r;
	yxml_t x[1];
	yxml_init(x, stack, sizeof(stack));

	FILE *fp;
	long lSize;
	fp = fopen (  filename , "rb" );
	if( !fp ) perror(filename),exit(1);

	fseek( fp , 0L , SEEK_END);
	lSize = ftell( fp );
	rewind( fp );

	while((c = getc(fp)) != EOF) {
		r = yxml_parse(x, c);
		y_printres(x, r, ledges);
	}

	fclose(fp);
	return list_size(ledges);
}

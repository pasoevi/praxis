#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char *DOC_TEMPLATE_START =
        "<?xml version=\"1.0\" ?>\n<OBJECTS>\n";
const char *DOC_TEMPLATE_END =
        "\n</OBJECTS>\n";
const char *ELEMENT_TEMPLATE =
        "<object type=\"%s\" x=\"%d\" y=\"%d\" dx=\"%d\" dy=\"%d\" width=\"%d\" height=\"%d\" numFrames=\"1\"/>";

const char NUM_ENEMIES = 100;

const int TOP = -2000;
const int BOTTOM = 0;

int randRange(int min, int max){
        return (rand() % (max + 1 - min)) + min;
}

int main(int argc, char *argv[]){
        /* Number of enemies to generate */
        int numEnemies = 100;

        /* Get command line arguments */
        int index, opt;

        opterr = 0;
        srand(1);

        while((opt = getopt(argc, argv, "n:")) != -1){
                switch(opt){
                case 'n':
                        numEnemies = atoi(optarg);
                        break;
                default:
                        printf("Usage: mklevel [-n num_enemies]");
                }
        }

        printf(DOC_TEMPLATE_START);

        int i;
        for(i = 0; i < numEnemies; i++){
                int x = randRange(0, 750);
                int y = randRange(TOP, BOTTOM);
                int w = randRange(30, 90);
                int h = randRange(40, 100);
                int dx = 0;
                int dy = 500.f / (w + h);

                printf(ELEMENT_TEMPLATE, "alien_ship", x, y, dx, dy, w, h);
                printf("\n");
        }

        for(i = 0; i < numEnemies; i++){
                int x = randRange(0, 750);
                int y = randRange(TOP, BOTTOM);
                int w = 30;
                int h = 30;
                int dx = 0;
                int dy = 300.f / (w + h);

                printf(ELEMENT_TEMPLATE, "powerup", x, y, dx, dy, w, h);
                printf("\n");
        }

        printf(DOC_TEMPLATE_END);
        return 0;
}

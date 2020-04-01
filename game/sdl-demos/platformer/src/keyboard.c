#include "keyboard.h"
#include <stdio.h>

extern Uint8 *keystates;

int isKeyDown(SDL_Scancode key) {
        if(keystates != 0) {
                return keystates[key];
        }
        return 0;
}

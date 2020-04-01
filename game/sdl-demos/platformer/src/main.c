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

#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "gamestate.h"
#include "keyboard.h"

const char *PROGRAM_NAME = "Invaders";

SDL_Window *window = NULL;
SDL_GLContext context;
const Uint8 *keystates;
int globalTime;

int WINDOW_W = 800;
int WINDOW_H = 600;

enum{
        FPS = 40,
};

const int SKIP_TICKS = 1000 / FPS;

bool renderQuad = true;

void destroy(void* data) {
        if(data != NULL){
                free(data);
        }
}

/* Start up SDL, create window and initialise opengl */
static int init(){
        int success = 0;

        if(SDL_Init(SDL_INIT_VIDEO) < 0){
                printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() ); success = false;
                success = -1;
        }else{
                /* Use OpenGL 2.1 */
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

                /* Create Window */
                window = SDL_CreateWindow(PROGRAM_NAME,
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_W, WINDOW_H,
                                          SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
                if( window == NULL ) {
                        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
                        success = -2;
                }else{
                        context = SDL_GL_CreateContext(window);
                        if(context == NULL){
                                printf("OpenGL context couldn not be created! SDL Error %s\n", SDL_GetError());
                        }else{
                                /* Use Vsync */
                                if(SDL_GL_SetSwapInterval(1) < 0){
                                        printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
                                }

                                /* Initialise OpenGL */
                                if(initGL() < 0){
                                        printf("unable to initialise OpenGL!\n");
                                        success = -3;
                                }
                        }
                }
        }
        return success;
}

/* Initialise matrices and clear color */
int initGL(){
        int success = 0;
        GLenum error = GL_NO_ERROR;

        /* Initialise projection matrix */
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, WINDOW_W, WINDOW_H,  0.0, 1.0, -1.0);

        /* Check for error */
        error = glGetError();
        if(error != GL_NO_ERROR){
                printf("Error initialising OpenGL! %s\n", gluErrorString(error));
                success = -1;
        }
        /* Initialise Modelvie Matrix */
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        /* Save the default modelview matrix */
        glPushMatrix();

        /* Check for error */
        if(error != GL_NO_ERROR){
                printf("Error initialising OpenGL! %s\n", gluErrorString(error));
                success = -2;
        }

        /* Initialise clear color */

        glClearColor(0.f, 0.f, 0.f, 1.f);

        /* Check for error */
        error = glGetError();
        if(error != GL_NO_ERROR){
                printf("Error initialising OpenGL! %s\n", gluErrorString(error));
                success = -3;
        }

        return success;
}

/* Input handler */
static void handleKeys(unsigned char key, int x, int y){
        /* Toggle quad */
        if(key == 'q'){
                renderQuad = !renderQuad;
        }
}

/* Per frame update */
static void update(){

}

/* Render quad to the screen */
static void render(){
        /* nothing here */
}

/* Free media and shut down SDL */
static void close(){
        SDL_DestroyWindow(window);
        window = NULL;
        SDL_Quit();
}

int main(int argc, char *argv[]){
        List states;

        struct GameStateMachine tmpFSM;
        struct GameState playState;

        struct GameStateMachine *fsm;

        if(init() < 0){
                printf("Failied to initialise!\n");
        }else{
                list_init(&states, destroy);
                tmpFSM = (struct GameStateMachine){
                        &states, pushState, changeState, popState, popAllStates
                };

                fsm = &tmpFSM;

                playState = (struct GameState){
                        &playUpdate, &playDraw, &playOnEnter,
                        &playOnExit, GAME_STATE_PLAY, context
                };

                fsm->pushState(fsm, &playState);

                bool running = true;
                SDL_Event e;

                /* Event handler */
                /*
                  Uint32 nextGameTick = SDL_GetTicks();
                  Uint32 sleepTime = 0;
                */
                while(running){
                        /*
                          nextGameTick += SKIP_TICKS;
                          sleepTime = nextGameTick - SDL_GetTicks();
                          if(sleepTime > 0){
                          SDL_Delay(sleepTime);
                          }
                        */

                        struct GameState *currentState = (struct GameState*)
                                (list_tail(fsm->gameStates)->data);

                        currentState->update(fsm);
                        currentState->render(currentState);

                        /* Update screen */
                        SDL_GL_SwapWindow(window);
                        while(SDL_PollEvent(&e) != 0){
                                keystates = SDL_GetKeyboardState(0);
                                if(e.type == SDL_QUIT){
                                        fsm->popState(fsm);
                                        running = false;
                                }
                        }
                }
        }
        /* Free resources and close SDL */
        list_destroy(&states);
        close();

        return EXIT_SUCCESS;
}

#include "statemgr.h"
#include "stack.h"

static tStack gameStateStack;
static bool bRunningFlag=false;

signed int initGameStateMgr(){
  if(initStack(&gameStateStack, 0, sizeof(sGameState))<0) return -1;
  bRunningFlag=true;
  return 0;
}

void deinitGameStateMgr(){
  deinitStack(&gameStateStack);
  return;
}

void changeState(sGameState *pState){
  sGameState *ptempState=0;
 
  if(!isStackEmpty(&gameStateStack)){
   
    //cleanup current state
    ptempState=(sGameState *)getTopStackElement(&gameStateStack);
    //deinit it
    ptempState->deinit();
    //remove it
    popStack(&gameStateStack);
  }
 
  //store and init new state
  pushStack(&gameStateStack, (const void *)pState);
  ptempState=(sGameState *)getTopStackElement(&gameStateStack);
  ptempState->init();
}

void popState(){
  sGameState *ptempState=0;
 
  if(!isStackEmpty(&gameStateStack)){
   
    //cleanup current state
    ptempState=(sGameState *)getTopStackElement(&gameStateStack);
    //deinit it
    ptempState->deinit();
    //remove it
    popStack(&gameStateStack);
  }
 
  //resume previous
  if(!isStackEmpty(&gameStateStack)){
    ptempState=(sGameState *)getTopStackElement(&gameStateStack);
    resumeGamestate (ptempState);
  }
}

void pushState(sGameState *pState){
  sGameState *ptempState=0;
   
  if(!isStackEmpty(&gameStateStack)){
 
    ptempState=(sGameState *)getTopStackElement(&gameStateStack);
    pauseGamestate (ptempState);
  }
 
  pushStack(&gameStateStack, (const void *)pState);  
  ptempState=(sGameState *)getTopStackElement(&gameStateStack);
  ptempState->init();
 
}


void process(){
  sGameState *ptempState=0;
  ptempState=(sGameState *)getTopStackElement(&gameStateStack);
  ptempState->process();
}

bool isGameRunning(){
  return bRunningFlag;
}

void Quit(){
  bRunningFlag=false;
}

// And here is an example usage in main program function (main.c):
//our game state manager
#include "statemgr.h"

//headers with all the states
// #include "IntroState.h"
// #include "MainMenuState.h"
// #include "CreditsState.h"
// #include "SettingsState.h"

int main(int argc, char **argv){

  // ...init all subsystems here (input, sound, video etc.. )

  //init game states
  //  initAndRegisterIntroState();
  //   initAndRegisterMmenuState();
  //   initAndRegisterSettingsState();
  //   initAndRegisterCreditsState();

  if(initGameStateMgr()<0){

    puts("Error: state manager error\n");
    // deinit stuff here
    // ...
    return 1;
  }

  // load the intro
  changeState(&introState);

  // main loop
  while ( isGameRunning() == true ){
    process();
  }

  deinitGameStateMgr();

  // deinit all subsystems here (input, sound, video etc.. )

  return 0;

  And example, minimal state implementation can look like this:
    IntroState.h
#ifndef __INTRO_STATE_H__
#define __INTRO_STATE_H__

#include "states/gamestate.h"

    sGameState introState;

  void initAndRegisterIntroState();

#endif

  IntroState.c
#include "states/statemgr.h"
#include "IntroState.h"
#include "MainMenuState.h"

    static unsigned long IntroStateInit(){
    puts("Intro State Init\r\n");
    return 1;
  }

  static unsigned long IntroStateDeinit(){
    puts("Intro State deinit. See ya!\r\n");
    return 0; //quits the program
  }

  static void IntroStateUpdate(){
    puts("Intro State update\r\n");
  }

  static void IntroStateDraw(){
    puts("Intro State draw\r\n");

  }

  static void IntroStateHandleInput(){

    puts("Intro State handle input\r\n");
    // for example, on certain input from mouse/keyboard ...
    // to go to another state call changeState(&someState)
    // or pause current state and go to another with pushState(&someState)
    // or resume previous state which is on stack with popState();
    // or exit running program loop and quit program by calling Quit();

  }

  static unsigned long IntroStateMainLoop(){

    if(!introState.bPaused){
      IntroStateHandleInput();
      IntroStateUpdate();
      IntroStateDraw();
    }

    //screenswap

    return 1;
  }

  void initAndRegisterIntroState(){
    initGamestate(&introState,IntroStateInit,IntroStateMainLoop,IntroStateDeinit);
  }

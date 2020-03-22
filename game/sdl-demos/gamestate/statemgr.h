#ifndef __STATE_MGR__H__
#define __STATE_MGR__H__

// (c)Pawel Goralski 12'2011
// www: gamedev.nokturnal.pl

#include "gamestate.h"

signed int initGameStateMgr(void);
void deinitGameStateMgr();

void changeState(sGameState *pState);
void popState();
void pushState(sGameState *pState);

void process();
bool isGameRunning();
void Quit();

#endif

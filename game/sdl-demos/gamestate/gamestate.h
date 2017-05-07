#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include <stdbool.h>

// (c)Pawel Goralski 12'2011
// www: gamedev.nokturnal.pl

typedef unsigned int (*funcPtrInt)();

typedef struct {
  funcPtrInt init;
  funcPtrInt process;
  funcPtrInt deinit;
  bool bPaused;
} sGameState;

void initGamestate (sGameState *state,const void *init,const void *process,const void *deinit);
void pauseGamestate (sGameState *state);
void resumeGamestate (sGameState *state);

#endif

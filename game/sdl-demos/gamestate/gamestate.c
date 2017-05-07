#include "gamestate.h"

void initGamestate (sGameState *state,const void *init,const void *process,const void *deinit){
  state->init=init;
  state->process=process;
  state->deinit=deinit;

  state->bPaused=false;

};

inline void pauseGamestate (sGameState *state){
  state->bPaused=true;
}

inline void resumeGamestate (sGameState *state){
  state->bPaused=false;
}

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

#include "gamestate.h"

int initFSM(List *states, void(*destroy)(void*), struct GameStateMachine **fsm){
	struct GameStateMachine *machine = malloc(sizeof machine);
        list_init(states, destroy);
	
	machine->gameStates = states;
	machine->pushState = pushState;
	machine->changeState = changeState;
	machine->popState = popState;
	machine->popAllStates = popAllStates;
	
        *fsm = machine;
        return 0;
}

void pushState(struct GameStateMachine *fsm, struct GameState *state) {
        list_ins_next(fsm->gameStates, (fsm->gameStates)->tail, state);
        state->onEnter(state);
}

void changeState(struct GameStateMachine *fsm, struct GameState *state) {
        if (list_size(fsm->gameStates) > 0) {
                struct GameState *curState = (struct GameState*)
                        list_tail(fsm->gameStates)->data;
                if (curState->stateId == state->stateId) {
                        return;
                }
        }
        popState(fsm);
        pushState(fsm, state);
}

void popState(struct GameStateMachine *fsm) {
        if (list_size(fsm->gameStates) != 0) {
		struct GameState * curState;
                /* Get the second to last element. */
                ListElmt *iter = list_head(fsm->gameStates);
                if (list_size(fsm->gameStates) > 1) {
                        while (!list_istail(list_next(iter))) {
                                iter = list_next(iter);
                        }
                }
                
                if (list_next(iter) == NULL) {
                        curState = (struct GameState*) list_data(iter);
                        if (curState->onExit()) {
                                list_rem_next(fsm->gameStates, NULL, (void*)&curState);
                        }
                }
                else {
                        curState = (struct GameState*) list_data(list_next(iter));
                        if (curState->onExit()) {
                                list_rem_next(fsm->gameStates, iter, (void*)&curState);
                        }
                }
        }
}

void popAllStates(struct GameStateMachine *fsm) {
        int numStates = fsm->gameStates->size;
        int i = 0;
        for (i = 0; i < numStates; i++){
                fsm->popState(fsm);
        }
}

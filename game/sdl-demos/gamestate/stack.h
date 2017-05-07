#ifndef __STACK_H__
#define __STACK_H__
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
// (c)Pawel Goralski 12'2011
// www: gamedev.nokturnal.pl

//stack for storing game states
#define DEFAULT_MAXSTACK 20

typedef struct {
 size_t top;  // top of stack
 size_t size; // current max size of a stack, if we try to go past this threshold, then
              // it's size will be increased by DEFAULT_MAXSTACK elements
 unsigned long elementSize;
 void *stack;
} tStack;

//if initialMaxSize==0, then maximal initial size is set to DEFAULT_MAXSTACK
signed long initStack(tStack *pPtr, int initialMaxSize, unsigned int elementSize);

//void element has to be of the constant size
void pushStack(tStack *pPtr, const void *newElement);
void popStack(tStack *pPtr);
void *getTopStackElement();
bool isStackFull(tStack *pPtr);
bool isStackEmpty(tStack *pPtr);
void deinitStack(tStack *pPtr);

#endif

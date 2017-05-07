#include "stack.h"

// (c)Pawel Goralski 12'2011
// www: gamedev.nokturnal.pl

//if initialMaxSize==0, then maximal initial size is set to DEFAULT_MAXSTACK
signed long initStack(tStack *pPtr, int initialMaxSize, unsigned int elementSize) {
  pPtr->top=0;
  pPtr->stack=0;
  pPtr->elementSize=elementSize;

  if(initialMaxSize==0) {
    pPtr->size = DEFAULT_MAXSTACK;
  }else{
    pPtr->size = initialMaxSize;
  }

  //allocate memory
  void *pNewStack=0;

  pNewStack=malloc(elementSize*pPtr->size);

  if(pNewStack==0) return -1;

  memset(pNewStack,0,elementSize*pPtr->size);

  pPtr->stack=pNewStack;

  return 0;
}

//void element has to be of the constant size
void pushStack(tStack *pPtr, const void *newElement){
 
  if(pPtr->top==pPtr->size){
 
    //stack underflow
    pPtr->size=pPtr->size + DEFAULT_MAXSTACK;

    if(realloc(pPtr->stack,pPtr->size*pPtr->elementSize)==NULL){
      //Houston we have a problem. nothing can be done... we are dead...
      puts("Warning: Stack overflow!\r\t");
    }
    return;
  }
  else{
    unsigned long dst;

    dst=((unsigned long)pPtr->stack)+((++pPtr->top)*(pPtr->elementSize));

    memcpy((void *)dst,newElement,pPtr->elementSize);
    return;
  }

}

void *getTopStackElement(tStack *pPtr){

  //we assume stack is not empty
  unsigned long adr=((unsigned long)pPtr->stack)+(pPtr->top*pPtr->elementSize);

  //return removed element
  return (void *)adr;
}

void popStack(tStack *pPtr){

  if(pPtr->top==0){
    //stack underflow
    puts("Warning: Stack underflow!\r\t");
  }
  else {
    --pPtr->top;
  }
}

bool isStackFull(tStack *pPtr){
  if(pPtr->top==(pPtr->size-1))
    return true;
  else
    return false;
}

bool isStackEmpty(tStack *pPtr){

  if(pPtr->top==0)
    return true;
  else
    return false;

}

void deinitStack(tStack *pPtr){

  free(pPtr->stack);

  pPtr->top=0;
  pPtr->stack=0;
  pPtr->elementSize=0;
  pPtr->size = 0;

}

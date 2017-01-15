#include "list.h"
#include <stdlib.h>
typedef List Stack;

void init_stack(Stack *stack, void(*destroy)(void *));
void push(Stack *stack, void *node);
void *pop(Stack *stack);

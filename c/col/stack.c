#include "stack.h"

void init_stack(Stack *stack, void(*destroy)(void *)){
  list_init(stack, destroy);
}
void push(Stack *stack, void *data){
  list_ins_next(stack, NULL, data);
}
void *pop(Stack *stack){
  ListElmt *node = stack->head;

  if(stack->head == NULL){
    return NULL;
  }else if(node == stack->tail){
    stack->head = stack->tail = NULL;
    void *data = node->data;
    free(node);
    return data;
  }else{
    stack->head = stack->head->next;
    void *data = node->data;
    free(node);
    return data;
  }

}

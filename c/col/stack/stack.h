#include "list.h"

typedef List Queue;

void init_queue(Queue *queue, void(*destroy)(void *));
void enqueue(Queue *queue, void *node);
void *dequeue(Queue *queue);

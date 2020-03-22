#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "stack.h"

struct Employee{
	char name[100];
	short age;
};

void destroy(void* param) {
	printf("That's how you kill it");
}

testQueue(){
  struct Employee *sergi = (struct Employee*) malloc(sizeof(struct Employee));
  strncpy(sergi->name, "Sergi", strlen("Sergi") + 1);
  sergi->age = 23;
  struct Employee *sophie = (struct Employee*) malloc(sizeof(struct Employee)); 
  strncpy(sophie->name, "Sophie", strlen("Sophie") + 1);
  sophie->age = 20;
  struct Employee *ula = (struct Employee*) malloc(sizeof(struct Employee));
  strncpy(ula->name, "Ula", strlen("Ula") + 1);
  ula->age = 25;

  Queue queue;
  init_queue(&queue, destroy);
  enqueue(&queue, sergi);
  enqueue(&queue, sophie);
  enqueue(&queue, ula);

  Stack stack;
  init_stack(&stack, destroy);
  push(&stack, sergi);
  push(&stack, sophie);
  push(&stack, ula);

  void *data = dequeue(&queue);
  printf("Dequeued %s\n", ((struct Employee*)data)->name);

  data = dequeue(&queue);
  printf("Dequeued %d\n", ((struct Employee*)data)->age);

  data = dequeue(&queue);
  printf("Dequeued %d\n", ((struct Employee*)data)->age);

  data = pop(&stack);
  printf("Popped %s\n", ((struct Employee*)data)->name);

  data = pop(&stack);
  printf("Popped %d\n", ((struct Employee*)data)->age);

  data = pop(&stack);
  printf("Popped %d\n", ((struct Employee*)data)->age);
}

int main(int argc, char** argv) {
  testQueue();

  return (0);
}

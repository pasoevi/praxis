#include "queue.h"

void init_queue(Queue *queue, void(*destroy)(void *)){
	list_init(queue, destroy);
}
void enqueue(Queue *queue, void *node){
	list_ins_next(queue, NULL, node);
}
void *dequeue(Queue *queue){
	ListElmt *tmp = queue->head;
	void *data;

	if(queue->head == NULL){
		data = NULL;
	} else if(queue->head == queue->tail){
		queue->head = queue->tail = NULL;
		data = tmp->data;
		free(tmp);
	} else{
		while(tmp->next != queue->tail){
			tmp = tmp->next;
		}
		queue->tail = tmp;
		tmp = tmp->next;
		queue->tail->next = NULL;
		data = tmp->data;
		free(tmp);
	}
	return data;
}
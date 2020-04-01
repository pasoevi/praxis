#include "tree.h"

int insert_node(struct Node *tree, void *data){
	if(data == NULL || tree == NULL){
		return -1;
	}

	


struct Node{
	void *data;
	struct Node *left;
	struct Node *right;
};
	
int insert_node(struct Node *tree, void *data);

#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

void insertNode(TreeNode **root, COMPARE compare, void *data){
  TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  if(*root == NULL){
    *root = node;
    return;
  }

  while(1){
    if(compare((*root)->data, data) > 0){
      if((*root)->left != NULL){
	*root = (*root)->left;
      }else{
	(*root)->left = node;
	break;
      }
    }else{
      if((*root)->right == NULL){
	(*root)->right = node;
      }
      else{
	(*root)->right = node;
	break;
      }
    }
  }
}

void inOrder(TreeNode **root, DISPLAY display){
  if(root != NULL){
    inOrder(root->left, display);
    display(root->data);
    inOrder(root->right);
  }
}

void postOrder(TreeNode **root, DISPLAY display){
  if(root != NULL){
    postOrder(root->left, display);
    postOrder(root->right, display);
    display(root->data);
  }
}

void preOrder(TreeNode **root, DISPLAY display){
  if(root != NULL){
    display(root-data);
    preOrder(root->left, display);
    preOrder(root->right, display);
  }
}


int compareInt(void *v1, void *v2){
  int *a = (int*)(v1);
  int *b = (int*)(v1);

  int res = 0;
  if(*a < *b){
    res = -1;
  }else if(*a == *b){
    res = 0;
  }else{
    res = 1;
  }
}

int main(void){
  printf("Test\n");
  int a = 2, b = 1, c = 3, d = 4;
  TreeNode *tree = NULL;
  insertNode(&tree, (COMPARE) compareInt, &a);
  insertNode(&tree, (COMPARE) compareInt, &b);
  insertNode(&tree, (COMPARE) compareInt, &c);
  insertNode(&tree, (COMPARE) compareInt, &d);
  return 0;
}

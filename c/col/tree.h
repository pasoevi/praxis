typedef struct _tree {
  void *data;
  struct _tree *left;
  struct _tree *right;
} TreeNode;

typedef int (*COMPARE)(void*, void*);
void insertNode(TreeNode **root, COMPARE compare, void *data);

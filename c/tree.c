struct node
{
    int value;
    struct node* left;
    struct node* right;
};


int sumTheTreeValues(struct node* root)
{
    if (!root) {
        return root;
    } else if (!root->right) {
        return root->value + sumTheTreeValues(root->left);
    } else if (!root->left) {
        return root->value + sumTheTreeValues(root->right);
    } else {
        return root->value + sumTheTreeValues(root->left) + sumTheTreeValues(root->right);
    }
  
    return 0;
}

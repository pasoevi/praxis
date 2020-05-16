/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} preorder
 * @return {TreeNode}
 */
var bstFromPreorder = function(preorder) {
    if (preorder.length === 0) {
        return null;
    }

    rootValue = preorder[0];

    const smaller = [];
    const larger = [];

    let i = 1;
    while (i < preorder.length && preorder[i] < rootValue) {
        smaller.push(preorder[i]);
        i++;
    }

    while (i < preorder.length) {
        larger.push(preorder[i]);
        i++;
    }

    const root = new TreeNode(rootValue);
    root.left = bstFromPreorder(smaller);
    root.right = bstFromPreorder(larger);

    return root;
};
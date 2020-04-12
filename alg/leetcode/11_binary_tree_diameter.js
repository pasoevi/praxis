/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function (root) {
    return getDiameterAndHeight(root)[0];
};



function getDiameterAndHeight(root) {
    const result = [0,0];
    if (root === null || root === undefined) {
        return result;
    }
    const leftResult = getDiameterAndHeight(root.left);
    const rightResult = getDiameterAndHeight(root.right);
    const height = Math.max(leftResult[1], rightResult[1]) + 1;
    const rootDiameter = leftResult[1] + rightResult[1] + 1;
    const leftDiameter = leftResult[0];
    const rightDiameter = rightResult[0];
    result[0] = Math.max(rootDiameter, Math.max(leftDiameter, rightDiameter));
    result[1] = height;

    return result;
}

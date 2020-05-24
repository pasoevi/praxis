/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function (root, k) {
    let table = findSmallestArray(root);
    return table[k - 1];
};

function findSmallestArray(root) {
    let result = [];
    if (root === null) {
        return result;
    }

    if (root.left !== undefined) {
        result.push(...findSmallestArray(root.left));
    }

    result.push(root.val);

    if (root.right !== undefined) {
        result.push(...findSmallestArray(root.right));
    }

    return result;
}

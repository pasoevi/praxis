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
 * @param {number} x
 * @param {number} y
 * @return {boolean}
 */
var isCousins = function (root, x, y) {
    const xLevel = getLevel(root, x, 1);
    const yLevel = getLevel(root, y, 1);
    const siblings = isSiblings(root, x, y);
    console.log(
        `xLevel: ${xLevel}, yLevel: ${yLevel}, isSiblings: ${siblings}`,
    );
    return xLevel === yLevel && !isSiblings(root, x, y);
};

function getLevel(root, value, level) {
    if (root === null) {
        return 0;
    }

    if (root.val === value) {
        return level;
    }

    const leftLevel = getLevel(root.left, value, level + 1);
    if (leftLevel) {
        return leftLevel;
    }

    return getLevel(root.right, value, level + 1);
}

function isSiblings(root, x, y) {
    if (root === null) {
        return false;
    }

    if (
        root.left &&
        root.left.val === x &&
        root.right &&
        root.right.val === y
    ) {
        return true;
    }

    if (
        root.left &&
        root.left.val === y &&
        root.right &&
        root.right.val === x
    ) {
        return true;
    }

    return isSiblings(root.left, x, y) || isSiblings(root.right, x, y);
}

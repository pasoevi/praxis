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
var bstFromPreorder = function (preorder) {
    const output = [];
    for (let )
};

function insert(root, value) {
    const newElement = new TreeNode(value);
    if (value < root.val) {
        if (root.left === null) {
            root.left = newElement;
        } else {
            insert(root.left, value);
        }
    } else if (value > root.val) {
        if (root.right === null) {
            root.right = newElement;
        } else {
            insert(root.right, value);
        }
    }

    return root;
}


// ------------------------------------------------------------



def getPreIndex():
    return constructTreeUtil.preIndex

def incrementPreIndex():
    constructTreeUtil.preIndex += 1

# A recursive function to construct BST from pre[].
# preIndex is used to keep track of index in pre[]
def constructTreeUtil(pre, key, mini, maxi, size):

    # Base Case
    if(getPreIndex() >= size):
        return None

    root = None

    # If current element of pre[] is in range, then
    # only it is part of current subtree
    if(key > mini and key < maxi):

        # Allocate memory for root of this subtree
        # and increment constructTreeUtil.preIndex
        root = Node(key)
        incrementPreIndex()

        if(getPreIndex() < size):

            # Construct the subtree under root
            # All nodes which are in range {min.. key} will
            # go in left subtree, and first such node will
            # be root of left subtree
            root.left = constructTreeUtil(pre,
                         pre[getPreIndex()], mini, key, size)

            # All nodes which are in range{key..max} will
            # go to right subtree, and first such node will
            # be root of right subtree
            root.right = constructTreeUtil(pre,
                     pre[getPreIndex()], key, maxi, size)

    return root

# This is the main function to construct BST from given
# preorder traversal. This function mainly uses
# constructTreeUtil()
def constructTree(pre):
    constructTreeUtil.preIndex = 0
    size = len(pre)
    return constructTreeUtil(pre, pre[0], INT_MIN, INT_MAX, size)


# A utility function to print inorder traversal of Binary Tree
def printInorder(node):

    if node is None:
        return
    printInorder(node.left)
    print node.data,
    printInorder(node.right)


# Driver program to test above function
pre = [10, 5, 1, 7, 40, 50]
root = constructTree(pre)

print "Inorder traversal of the constructed tree: "
printInorder(root)


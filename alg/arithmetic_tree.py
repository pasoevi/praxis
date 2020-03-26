"""
Suppose an arithmetic expression is given as a binary tree.
Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.
Given the root to such a tree, write a function to evaluate it.
For example, given the following tree:
    *
   / \
  +    +
 / \  / \
3  2  4  5
You should return 45, as it is (3 + 2) * (4 + 5).
"""

class Node:
    def __init__(self, value, left=None, right=None):
        this.value = value
        this.left = left
        this.right = right

root = Node("*", Node("+", Node(3), Node(2)), Node("+", Node(4), Node(5)))

def solve(node):
    if node.left is None or node.right is None:
        return node.value
    elif node.value == "+":
        return solve(node.left) + solve(node.right)
    elif node.value == "-":
        return solve(node.left) - solve(node.right)
    elif node.value == "*":
        return solve(node.left) * solve(node.right)
    elif node.value == "/":
        return solve(node.left) / solve(node.right)

print(solve(root))



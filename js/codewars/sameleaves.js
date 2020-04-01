function treeHeight(node) {
    if (!node) {
        return 0;
    }
    
    return 1 + Math.max(treeHeight(node.getLeft()), treeHeight(node.getRight()));
}

function isPerfect(node) {

    console.log(node.getValue());

    if (!node) {
        return true;
    }
    
    if (!node.getLeft() && !node.getRight()) {
        return true;
    }
    
    if ((node.getLeft() && !node.getRight()) ||
        (node.getRight() && !node.getLeft())) {
        return false;
    }
    
    if (treeHeight(node.getLeft()) !== treeHeight(node.getRight())) {
        return false;
    }
    
    return isPerfect(node.getLeft()) && isPerfect(node.getRight()); // TODO: implementation
}

function allLeavesAtSameLevel(node) {
    if (node === undefined) {
        return true;
    }
    
    if ((node.getLeft() && !node.getRight()) ||
        (node.getRight() && !node.getLeft())) {
        return true;
    }
    
    return isPerfect(node);
}

function Node(value, left, right) {
    this.getLeft = function () {
        return left;
    };

    this.getRight = function () {
        return right;
    };

    this.getValue = function () {
        return value;
    };
}

var sameLevel = new Node(1,new Node(2,new Node(7)),new Node(3,new Node(4)));
var oneLeaf = new Node(1,undefined,new Node(2));
var diffLevel = new Node(1,new Node(2),sameLevel);

console.log(allLeavesAtSameLevel(sameLevel));
// console.log(allLeavesAtSameLevel(oneLeaf));
// console.log(allLeavesAtSameLevel(diffLevel));

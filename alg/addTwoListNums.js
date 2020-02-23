/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    return numToList(listToNum(l1) + listToNum(l2));
};

function listToNum(list) {
    if (list === null) {
        return "";
    }
    let numStr = "";
    let iter = list;
    while (iter !== null) {
        numStr += iter.val;
        iter = iter.next;
    }

    return new BigInt(numStr.split("").reverse().join(""));
}

function numToList(num) {
    if (num === null) {
        return null;
    }

    let list = null;
    let node = list;
    const str = (num + "").split("").reverse().join("");
    for (let c of str) {
        if (node === null) {
            node = new ListNode(c);
            list = node;
        } else {
            node.next = new ListNode(c);
            node = node.next;
        }
    }
    return list;
}

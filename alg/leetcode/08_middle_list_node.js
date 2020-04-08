/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var middleNode = function (head) {
    let iter = head;
    let length = 0;
    while (iter.next !== null) {
        iter = iter.next;
        length++;
    }

    let midElem = Math.ceil(length / 2);

    iter = head;
    let i = 0;
    while (iter.next !== null && i < midElem) {
        iter = iter.next;
        i++;
    }

    return iter;
};

console.log(middleNode([1, 2, 3, 4, 5]));
console.log(middleNode([1, 2, 3, 4, 5, 6]));
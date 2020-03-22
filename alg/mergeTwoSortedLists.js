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
var mergeTwoLists = function(l1, l2) {
    if (l1 === null) {
        return l2;
    } else if (l2 === null) {
        return l1;
    }

    if (l2.val > l1.val) {
        const tmp = l1;
        l1 = l2;
        l2 = tmp;
    }

    let l1Iter = l1;
    let l2Iter = l2;
    let newList;
    let item = null;
    while (l1Iter !== null || l2Iter !== null) {
        while (l2Iter !== null && (l1Iter === null || l2Iter.val <= l1Iter.val)) {
            if (item === null) {
                item = new ListNode(l2Iter.val);
                newList = item;
            } else {
                item.next = new ListNode(l2Iter.val);
                item = item.next;
            }
            l2Iter = l2Iter.next;
        }
        if (l1Iter === null) {
            continue;
        }
        if (item === null) {
            item = new ListNode(l1Iter.val);
            newList = item;
        } else {
            item.next = new ListNode(l1Iter.val);
            item = item.next;
        }
        l1Iter = l1Iter.next;
    }

    return newList;
};

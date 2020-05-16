var oddEvenList = function (head) {
    if (head === null || head.next === null) {
        return head;
    }
    let oddIter = head;
    let evenIter = head.next;
    const evenHead = head.next;
    while (oddIter != null && evenIter != null) {
        const tmp = evenIter.next;
        if (tmp !== null) {
            oddIter.next = evenIter.next;
            oddIter = oddIter.next;
            evenIter.next = oddIter.next;
            evenIter = evenIter.next;
        } else {
            evenIter = null;
        }
    }
    oddIter.next = evenHead;
    return head;
};

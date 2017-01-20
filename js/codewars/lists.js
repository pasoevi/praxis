function map(head, f) {
	if (head === null) {
  	    return null;
    }
    
    return new Node(f(head.data), map(head.next, f));
};

function map(head, f) {
	if (head === null) {
  	    return null;
    }
    
    return new Node(f(head.data), map(head.next, f));
};


function permutations(string) {
    if (string.length < 2) return string;

    var result = [];

    for (var i=0; i<string.length; i++) {
        var char = string[i];

        // Cause we don't want any duplicates:
        if (string.indexOf(char) != i) // if char was used already
            continue;           // skip it this time

        var remainingString = string.slice(0,i) + string.slice(i+1,string.length);

        for (var subPermutation of permutations(remainingString))
            result.push(char + subPermutation);

    }
    return result;
}


Function.method('curry', function ( ) {
    var slice = Array.prototype.slice,
        args = slice.apply(arguments),
        that = this;
    return function ( ) {
        return that.apply(null, args.concat(slice.apply(arguments)));
    };
});

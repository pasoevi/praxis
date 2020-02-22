function isPair(c1, c2) {
    const pairs = {
        "(": ")",
        "[": "]",
        ")": "(",
        "]": "[",
        "}": "{",
        "{": "}",
    };
    // console.log(`c1: ${c1} c2: ${c2} pairs[c1] === c2: ${pairs[c1] === c2}`)
    return pairs[c1] === c2;
}

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const queue = [];
    for (let c of s) {
        if (isPair(c, queue[queue.length-1])) {
            queue.pop();
        } else {
            queue.push(c);
        }
    }

    return queue.length === 0;
};

console.log(`(): ${isValid("()")}`);
console.log(`(]: ${isValid("(]")}`);
console.log(`()[]{}: ${isValid("()[]{}")}`);
console.log(`([)]: ${isValid("([)]")}`);

console.log((4 / 0) * -1)
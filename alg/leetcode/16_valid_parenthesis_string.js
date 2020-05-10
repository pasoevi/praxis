/**
 * @param {string} s
 * @return {boolean}
 */

function isPair(c1, c2) {
    if (c1 === undefined || c2 === undefined) {
        return false;
    }
    const pairs = {
        // "(": ")",
        ")": "(",
    };
    // console.log(`c1: ${c1} c2: ${c2} pairs[c1] === c2: ${pairs[c1] === c2}`)
    return pairs[c1] === c2;
}

function validate(s) {
    const queue = [];
    for (let c of s) {
        if (isPair(c, queue[queue.length - 1])) {
            queue.pop();
        } else {
            queue.push(c);
        }
    }
    // console.log(`${s}: ${queue.length === 0}`);
    return queue.length === 0;
}

var checkValidString = function (s) {
    let left = 0;
    let right = 0;

    for (let i = 0; i < s.length; i++ ) {
        if ('(*'.includes(s[i])) {
            left++;
        } else {
            left--
        }

        if (")*".includes(s[s.length - i - 1])) {
            right++;
        } else {
            right--;
        }

        if (left < 0 || right < 0) {
            return false;
        }
    }

    return true;
};

console.log(checkValidString("()"));
console.log(checkValidString("(*)"));
console.log(checkValidString("(*))"));
console.log(checkValidString(")("));
console.log(checkValidString("()"));

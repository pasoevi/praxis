/**
 * @param {string} S
 * @param {string} T
 * @return {boolean}
 */

function resolveBackspaces(str) {
    let a = "";
    for (let c of str) {
        if (c === "#") {
            if (a.length > 0) {
                // console.log(a);
                a = a.substring(0, a.length - 1);
                // console.log(a);
            }
        } else {
            a += c;
        }

    }

    return a;
}

var backspaceCompare = function(S, T) {
    return resolveBackspaces(S) === resolveBackspaces(T);
};

console.log(backspaceCompare("ab#c", "ad#c"));
console.log(backspaceCompare("ab##", "c#d#"));
console.log(backspaceCompare("a##c", "#a#c"));
console.log(backspaceCompare("a#c", "b"));
console.log(backspaceCompare("xywrrmp", "xywrrmu#p"));

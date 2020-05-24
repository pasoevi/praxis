/**
 * @param {number} n
 * @return {boolean}
 */

function sum(n) {
    const tmp = n
        .toString()
        .split("")
        .map((x) => x * x)
        .reduce((s, x) => x + s, 0);
    console.log(`n: ${n}, val: ${tmp}`);
    return tmp;
}

var isHappy = function (n) {
    let num = n;
    let i = 0;
    while (i++ < 1000) {
        num = sum(num);
        if (num === 1) {
            return true;
        }
    }
    return false;
};

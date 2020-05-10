/**
 * @param {string} s
 * @param {number[][]} shift
 * @return {string}
 */
var stringShift = function (s, shift) {
    let shiftSum = shift.reduce((sum, x) => sum + (x[0] === 0 ? -1 * x[1]: x[1]), 0);
    if (shiftSum === 0 || shiftSum % s.length === 0) {
        return s;
    }

    let result = s;
    const direction = shiftSum > 0 ? "right" : "left";
    const shiftTimes = Math.abs(shiftSum) % result.length;
    console.log(`Shifting ${direction}`);
    for (let i = 0; i < shiftTimes; i++) {
        if (direction === "left") {
            result = result.substring(1, result.length) + result[0];

        } else {
            result =
                result[result.length - 1] +
                result.substring(0, result.length - 1);
        }
    }

    // console.log(result);
    return result;
};

console.log(
    stringShift("abc", [
        [0, 1],
        [1, 2],
    ]) === "cab",
);
console.log(
    stringShift("abcdefg", [
        [1, 1],
        [1, 1],
        [0, 2],
        [1, 3],
    ]) === "efgabcd",
);

console.log(
    stringShift("wpdhhcj", [
        [0, 7],
        [1, 7],
        [1, 0],
        [1, 3],
        [0, 3],
        [0, 6],
        [1, 2],
    ]) === "hcjwpdh",
);
/**
 * @param {number} num
 * @return {boolean}
 */
var isPerfectSquare = function (num) {
    return guessSquare(num, 1, num);
};

function guessSquare(num, low, high) {
    if (low > high) {
        return false;
    }

    const middle = Math.round((low + high) / 2);
    if (middle * middle === num) {
        return middle;
    } else if (middle * middle < num) {
        return guessSquare(num, middle + 1, high);
    } else {
        return guessSquare(num, low, middle - 1);
    }
    return false;
}

/**
 * @param {number[]} arr
 * @return {number}
 */
var countElements = function (arr) {
    const elements = {};
    let count = 0;
    for (const num of arr) {
        elements[num] = true;
    }

    for (const num of arr) {
        if (elements[num + 1] !== undefined) {
            count++;
        }
    }

    return count;
};

console.log(countElements([1, 2, 3]));
console.log(countElements([1, 1, 3, 3, 5, 5, 7, 7]));
console.log(countElements([1, 3, 2, 3, 5, 0]));
console.log(countElements([1, 1, 2, 2]));
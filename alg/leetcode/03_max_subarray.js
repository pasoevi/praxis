/*
Given an integer array nums, find the contiguous subarray (containing
 at least one number) which has the largest sum and return its sum.
*/

function sum(array) {
    return array.reduce((accum, x) => accum + x, 0);
}

function maxSubArrayDNC(array) {
    if (array.length === 0) {
        return 0;
    } else if (array.length === 1) {
        // TODO: Try returning empty array if negative
        return array[0];
    } else if (array.length === 2) {
        const both = sum(array);
        if (both > array[0] && both > array[1]) {
            return both
        } else {
            return array[0] >= array[1] ? array[0] : array[1];
        }
    }else {
        const middle = Math.floor(array.length / 2);

        const left = maxSubArrayDNC(array.slice(0, middle));
        const right = maxSubArrayDNC(array.slice(middle));

        if (left >= right) {
            return left;
        } else {
            return right;
        }
    }
}

function maxSubArray(array) {
    let currentSum = array[0];
    const allNegative = array.filter(x => x < 0).length === array.length;
    let bestSum;

    for (let number of array) {
        console.log(currentSum, bestSum);
        if (currentSum === undefined) {
            currentSum = number;
        }

        currentSum = currentSum + number;
        if (currentSum < 0 && !allNegative) {
            currentSum = 0;
        }

        if (bestSum === undefined || currentSum > bestSum) {
            bestSum = currentSum;
        }
    }

    return bestSum;
}

// const example = [-2, 1, -3, 4, -1, 2, 1, -5, 4];

function max(a, b) {
    return a > b ? a : b;
}

function maxSub(array) {
    if (array.length === 0) {
        return 0;
    }

    if (array.length === 1) {
        return array[0];
    }

    let largestSum = array[0];
    let currentLargest = array[0];

    for (let number of array) {
        currentLargest = max(number, number + currentLargest);
        largestSum = max(currentLargest, largestSum);
    }

    return largestSum;
}

const example = [-2, -5];
const example2 = [-2, -3, 4, -1, -2, 1, 5, -3];
console.log(maxSub(example));
console.log(maxSub(example2));

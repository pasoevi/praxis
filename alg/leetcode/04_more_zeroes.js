 function moveZeroes(nums) {
     let zeroes = 0;
     for (let i = 0; i < nums.length; i++) {
         let start = i,
             end = i;
         while (nums[end] === 0 && end < nums.length) {
             end++;
             zeroes++;
         }
         i = start;
         nums.splice(start, end - start);
     }
     nums.push(...Array(zeroes).fill(0));
 }

 // const ex = [0, 0, 1];
 const ex = [0, 1, 0, 3, 12];
//  console.log(moveZeroes(ex));

///

var countLargestGroup = function (n) {
    const groups = [];
    for (let i = 1; i <= n; i++) {
        const sumDigits = i
            .toString()
            .split("")
            .reduce((accum, x) => accum + parseInt(x), 0);
        if (groups[sumDigits] !== undefined) {
            groups[sumDigits] += 1;
        } else {
            groups[sumDigits] = 1;
        }
    }

    let largestSum = 0;
    let largestCount = 0;
    for (let g in groups) {
        if (groups[g] > largestSum) {
            largestSum = groups[g];
            largestCount = 1;
        } else if (groups[g] == largestSum) {
            largestCount++;
        }
    }

    return largestCount;
};

// console.log(countLargestGroup(24));


/// Palindrome


 // (s = "annabelle"), (k = 2);

 /**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var canConstruct = function(s, k) {
    const palindromes = [];
    let charsUsed = "";

    for (let i = 0; i < k; i++) {

    }
};

/*
console.log(canConstruct("annabelle", 2));
console.log(canConstruct("leetcode", 3));
console.log(canConstruct("true", 4));
console.log(canConstruct("yzyzyzyzyzyzyzy", 2));
console.log(canConstruct("cr", 7));
*/

/**
 * @param {number[]} satisfaction
 * @return {number}
 */
var maxSatisfaction = function(satisfaction) {
    const sorted = satisfaction.slice();
    sorted.sort((a, b) => a - b);
    const numPositive = satisfaction.filter(x => x > 0).length;
    if (numPositive === 0) {
        return 0;
    }

    let likeTime = 0;
    let removeUntil = 0;
    while (sorted[removeUntil] < 0 && removeUntil < sorted.length - removeUntil && sorted[sorted.length-removeUntil-1] + sorted[removeUntil] < 0) {
        removeUntil++;
    }
    sorted.splice(0, removeUntil);
    for (let i = 1; i <= sorted.length; i++) {
        likeTime += sorted[i - 1] * i;
    }

    return likeTime;
};

console.log(maxSatisfaction([-1, -8, 0, 5, -9]));
console.log(maxSatisfaction([4, 3, 2]));
console.log(maxSatisfaction([-1, -4, -5]));
console.log(maxSatisfaction([-2, 5, -1, 0, 3, -3]));
console.log(
    maxSatisfaction([
        76,
        83,
        55,
        -36,
        -8,
        40,
        -60,
        -72,
        27,
        -32,
        37,
        1,
        77,
        24,
        -46,
        -26,
        20,
        -89,
        -35,
        -99,
        58,
        -7,
    ]),
); // Output:7194 Expected:7281
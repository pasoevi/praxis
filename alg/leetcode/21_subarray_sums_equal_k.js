/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function(nums, k) {
    const subarraySums = {};
    let currentSum = 0;
    let result = 0;

    for (let i = 0; i < nums.length; i++) {
        currentSum += nums[i];

        if (currentSum === k) {
            result++;
        }

        if (subarraySums[currentSum - k] !== undefined) {
            result += subarraySums[currentSum - k];
        }

        if (subarraySums[currentSum] !== undefined) {
            subarraySums[currentSum] += 1;
        } else {
            subarraySums[currentSum] = 1;
        }
    }

    return result;
};

console.log(subarraySum([1, 1, 1], 2));
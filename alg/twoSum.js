const { PerformanceObserver, performance } = require('perf_hooks');

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
function twoSum(nums, target) {
    const checked = new Map();
    for (let i = 0; i < nums.length; i++) {
        if (checked.get(target - nums[i]) !== undefined) {
            return [checked.get(target - nums[i]), i];
        } else {
            checked.set(nums[i], i);
        }
    }
};

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
function twoSumComplement(nums, target) {
    const checked = {}
    for (let i = 0; i < nums.length; i++) {
        if (checked[nums[i]] !== undefined) {
            return [checked[nums[i]], i];
        } else {
            checked[target - nums[i]] = i;
        }
    }
};

function twoSumBruteForce(nums, target) {
    for (let i = 0; i < nums.length; i++) {
        for (let j = i; j < nums.length; j++) {
            if (nums[i] + nums[j] === target) {
                return [i, j];
            }
        }
    }
};

const arraySize = 187998;
const example1 = [2, 7, 11, 15];
const example2 = Array.from({length: arraySize}, () => Math.floor(Math.random() * arraySize));

var t0 = performance.now();
console.log(twoSum(example2,9));
var t1 = performance.now();
console.log("Call to twoSum took " + (t1 - t0) + " milliseconds.");


var tBrute0 = performance.now();
console.log(twoSumComplement(example2,9));
var tBrute1 = performance.now();
console.log("Call to twoSumComplement took " + (tBrute1 - tBrute0) + " milliseconds.");
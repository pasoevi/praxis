/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
    const pivot = findPivot(nums);
    let low, high;
    if (nums[pivot] === target) {
        return pivot;
    }

    if (pivot < 0) {
        return binarySearch(nums, target, 0, nums.length - 1);
    }

    if (target > nums[nums.length - 1]) {
        low = 0;
        high = pivot;
    } else {
        low = pivot;
        high = nums.length - 1;
    }
    console.log(`nums: ${nums}, target: ${target}, low: ${0},  high: ${pivot}`);
    return binarySearch(nums, target, low, high);
};

function findPivot(nums) {
    if (nums.length < 2) {
        return 0;
    }
    let i = 0;
    for (i = 1; i < nums.length; i++) {
        if (nums[i] < nums[i - 1]) {
            console.log(`pivot: ${i}`);
            return i;
        }
    }

    console.log(`pivot: ${i}`);

    return -1;
}

function binSearch(nums, target, low, high) {
    let pivot;
    if (target > nums[high] || target < nums[low]) {
        return -1;
    }
    while (low < high) {
        if (nums[low] === target) {
            return low;
        }

        if (nums[high] === target) {
            return high;
        }
        pivot = Math.floor((low + high) / 2);

        if (nums[pivot] === target) {
            return pivot;
        }

        if (target < nums[pivot]) {
            console.log("too high");
            high = pivot;
        } else {
            console.log("too low");
            low = pivot;
        }
        console.log(
            `nums: ${nums}, target: ${target}, guess: ${nums[pivot]} low: ${low}, pivot: ${pivot} high: ${high}`,
        );
    }
    return -1;
}

function binarySearch(arr, target, low, high) {
    if (high < low) {
        return -1;
    }

    let mid = Math.floor((low + high) / 2);

    if (target === arr[mid]) {
        return mid;
    }
    if (target > arr[mid]) {
        return binarySearch(arr, target, mid + 1, high);
    }
    return binarySearch(arr, target, low, mid - 1);
}
const ex = [0, 1, 2, 4, 5, 6, 7];
// console.log(binarySearch(ex, 6, 0, ex.length-1));
//console.log(search([4, 5, 6, 7, 0, 1, 2], 3));
//console.log(search([3, 4, 5, 0, 1, 2], 3));
console.log(search([5, 1, 3], 3));
// console.log(binarySearch([1, 3], 2, 0, 1));
// console.log(search([1,3 ], 2));

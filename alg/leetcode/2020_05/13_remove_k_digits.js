/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNonDuplicate = function (nums, low, high) {
    if (low === undefined) {
        low = 0;
    }

    if (high === undefined) {
        high = nums.length - 1;
    }

    if (low > high) {
        return -1;
    }

    if (low === high) {
        return nums[low];
    }

    const mid = Math.round((low + high) / 2);

    if (mid % 2 === 0) {
        if (nums[mid] == nums[mid + 1]) {
            return singleNonDuplicate(nums, mid + 2, high);
        } else {
            return singleNonDuplicate(nums, low, mid);
        }
    } else if (mid % 2 == 1) {
        if (nums[mid] == nums[mid - 1]) {
            return singleNonDuplicate(nums, mid + 1, high);
        } else {
            return singleNonDuplicate(nums, low, mid - 1);
        }
    }
};

/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNonDuplicateNaive = function (nums) {
    for (let i = 0; i < nums.length; i++) {
        const prev = i === 0 ? NaN : nums[i - 1];
        const next = i + 1 >= nums.length ? NaN : nums[i + 1];
        if (nums[i] !== prev && nums[i] !== next) {
            return nums[i];
        }
    }
};

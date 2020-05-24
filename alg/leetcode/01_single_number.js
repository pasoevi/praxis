/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function (nums) {
    nums.sort();
    for (let i = 0; i < nums.length; i++) {
        const prev = i === 0 ? NaN : nums[i - 1];
        const next = i + 1 >= nums.length ? NaN : nums[i + 1];
        if (nums[i] !== prev && nums[i] !== next) {
            return nums[i];
        }
    }
};

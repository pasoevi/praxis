/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
    const elementFrequency = {};
    let highestFrequency = 0;
    let majorityElement;
    for (let num of nums) {
        if (elementFrequency[num] === undefined) {
            elementFrequency[num] = 1;
            if (majorityElement === undefined && highestFrequency === 0) {
                highestFrequency = 1;
                majorityElement = num;
            }
        } else {
            elementFrequency[num] += 1;
        }
        if (elementFrequency[num] > highestFrequency) {
            highestFrequency = elementFrequency[num];
            majorityElement = num;
        }
    }
    return majorityElement;
};

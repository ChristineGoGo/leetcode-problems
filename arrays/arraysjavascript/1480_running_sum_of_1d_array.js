/**
 * Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
 * Return the running sum of nums.
 * @param {number[]} nums
 * @return {number[]}
 */
// ----------------------- APPROACH 1: FOR LOOP ------------------------------------
 var runningSum = function(nums) {
    let result = [];
    let current = 0;

    for (let i = 0;  i < nums.length; i++) {
        current += nums[i];
        result.push(current);
    }
    return result;
};

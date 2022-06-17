/**
 * Given an integer array nums of length n, you want to create an array 
 * ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
 * Specifically, ans is the concatenation of two nums arrays.eturn the array ans.
 * @param {number[]} nums
 * @return {number[]}
 */
 var getConcatenation = function(nums) {
    let ans = [];
    for (let i = 0; i < nums.length; i++) {
        ans.push(nums[i]);
    }
    for (let i = 0; i < nums.length; i++) {
        ans.push(nums[i]);
    }
    return ans;
};

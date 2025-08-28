/* Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array. */

/**
 * @param {number[]} nums
 * @return {number}
 */
 var maxSubArray = function(nums) {
    let current_sum = nums[0];
    let max_sum = current_sum;
    for (let i = 1; i < nums.length; i++) {
        current_sum = Math.max(nums[i], current_sum + nums[i]);
        max_sum = Math.max(max_sum, current_sum);
    }
    return max_sum;
};


// test 1
// result = 6
console.log(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]));

// test 2
// result = 1
console.log(maxSubArray([1]));

// // test 3
// // result = 23
console.log(maxSubArray([5,4,-1,7,8]));

// // test 4
// // result = 30
console.log(maxSubArray([-2,1,-2,4,3,5,6,6,6]));


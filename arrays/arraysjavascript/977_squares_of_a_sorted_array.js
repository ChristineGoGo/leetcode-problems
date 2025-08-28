/**
 * Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
 * @param {number[]} nums
 * @return {number[]}
 */
// APPROACH 1: NAIVE APPROACH
//  var sortedSquares = function(nums) {
//     let result = [];
    
//     for(let i = 0; i < nums.length; i++) {
//         result.push(nums[i] * nums[i]);
//     }
    
//     result.sort(function(a, b){
//         return a - b;
//     });
//     return result;
// };

// APPROACH 2
var sortedSquares = function(nums) {    
    let [start, end] = [0, nums.length - 1];
    let result = []
    
    while (start <= end) {
        
        let curr = nums[start] < 0 ? nums[start] * - 1 : nums[start];

        if (curr <= nums[end]) {
            result.splice(0, 0, (nums[end] * nums[end]));
            end--;
        } else {
            result.splice(0, 0, (nums[start] * nums[start]));
            start++;
        }
    }

    return nums;
};


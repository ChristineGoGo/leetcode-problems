/* 

You are given a 0-indexed integer array nums and a target element target.

A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

 */

/** 
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 
*/
let targetIndices = function(nums, target) {
    sorted_arr = nums.sort((a, b) => a - b);
    let targets  = [];
    for (let i = 0 ; i < sorted_arr.length; i++) {
        if (sorted_arr[i] === target){
            targets.push(i);
        }
    }

    return targets

};

// Test : targetIndices([100,1,100], 100); === [1,2]
// Test : targetIndices([48,90,9,21,31,35,19,69,29,52,100,54,21,86,6,45,42,5,62,77,15,38]6); === [1]
console.log(targetIndices([1,2,5,2,3],2));
console.log(targetIndices([100,1,100],100));
console.log(targetIndices([48,90,9,21,31,35,19,69,29,52,100,54,21,86,6,45,42,5,62,77,15,38], 6))

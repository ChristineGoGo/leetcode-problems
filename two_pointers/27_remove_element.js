/**Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
 * The relative order of the elements may be changed.
 * Since it is impossible to change the length of the array in some languages,
 * you must instead have the result be placed in the first part of the array nums.
 * More formally, if there are k elements after removing the duplicates,
 * then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
 * Return k after placing the final result in the first k slots of nums.
 * Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
// ----------------------------------------- LENGTHY, SIMPLE AND INTUITIVE APPROACH --------------------------
//  var removeElement = function(nums, val) {
//     let k = 0;
//     let [start, end] = [0, nums.length - 1];
//     // set all val to '_'
//     for (let i = 0; i < nums.length; i++) {
//         if (nums[i] === val) nums[i] = '_';
//     }
//     // push all '_' to end while counting the rest
//     while (start < end) {
//         if (nums[start] !== '_') {
//             start++;
//         } else {
//             if (nums[end] !== '_') {
//                 let temp = nums[start];
//                 nums[start] = nums[end];
//                 // nums[end] = nums[start];
//                 nums[end] = '_';
//                 start++
//             }
//             end--;
//         }
//     }
//     // count all non "_"
//     for (let i = 0; i < nums.length; i++) {
//         if (nums[i] !== "_") k++;
//     }
//     return k;
// };

// ----------------------------------------- LESS LENGTHY APPROACH --------------------------
var removeElement = function(nums, val) {
    // s is the slow runner
    let s = 0;

    // i is the fast runner
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== val) {
            nums[s] = nums[i];
            s++;
        }
    }
    console.log(nums);
    return s;
};

// Custom Judge
// test1
// let nums = [3, 2, 2, 3]; // Input array
// let val = 3; // Value to remove
// let expectedNums = [2, 2]; // The expected answer with correct length.
//                             // It is sorted with no values equaling val.

// // test2
let nums = [0, 1, 2, 2, 3, 0, 4, 2]; // Input array
let val = 2; // Value to remove
let expectedNums = [0, 1, 3, 0, 4]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

let  k = removeElement(nums, val); // Calls your implementation
console.log(k);
var assert = require('assert');
assert(k === expectedNums.length);
// sort(nums, 0, k); // Sort the first k elements of nums
// for (let i = 0; i < actualLength; i++) {
//     assert(nums[i] == expectedNums[i]);
// }

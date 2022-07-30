/**
 * Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times. 
 * You may assume that the majority element always exists in the array
 * @param {number[]} nums
 * @return {number}
 */

// ------------------- APPROACH 1 --------------------------- 
//  var majorityElement = function(nums) {
//     let n = nums.length / 2;
//     let m = new Map();
    
//     for (let i = 0; i < nums.length; i++){
//         let curr = m.get(nums[i]);
//         if (curr === undefined) {
//             m.set(nums[i], 1);
//         } else {
//             m.set(nums[i], curr += 1);
//         }
//     }
    

//     for ([key, value] of m) {
//         if (value > n) return key;
//     }
// };

// ------------------- APPROACH 2 --------------------------- 
// create a map with the total count of each array element return the key with the maximum value

var majorityElement = function(nums) {
    let n = nums.length / 2;
    let m = new Map();
    
    for (let i = 0; i < nums.length; i++){
        let curr = m.get(nums[i]);
        if (curr === undefined) {
            m.set(nums[i], 1);
        } else {
            m.set(nums[i], curr += 1);
        }
    }

    for ([key, value] of m) {
        if (value > n) return key;
    }
};
// test1
let test1 = majorityElement([3,2,3]);
console.log(`test1: ${test1}`);

// test1
let test2 = majorityElement([2,2,1,1,1,2,2]);
console.log(`test2: ${test2}`);


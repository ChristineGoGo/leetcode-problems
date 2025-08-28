/**
 * Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
 * answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
 * answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
 * Note that the integers in the lists may be returned in any order.
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[][]}
 */
 var findDifference = function(nums1, nums2) {
    let answer = [];
    let ans1 = [];
    let ans2 = [];

    let set1 = new Set(nums1);
    let set2 = new Set(nums2);

    for (let item of set1) if (!set2.has(item)) ans1.push(item);
    for (let item of set2) if (!set1.has(item)) ans2.push(item);
    
    answer.push(ans1);
    answer.push(ans2);

    return answer[0];
    
};
// test1
// Input: nums1 = [1,2,3], nums2 = [2,4,6]
// Output: [[1,3],[4,6]]
//  console.log(findDifference([1,2,3], [2,4,6]));

// test2
// Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
// Output: [[3],[]]
console.log(findDifference([1,2,3,3], [1,1,2,2]));

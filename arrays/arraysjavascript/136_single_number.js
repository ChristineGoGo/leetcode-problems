/**
 * Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
 * You must implement a solution with a linear runtime complexity and use only constant extra space.
 * @param {number[]} nums
 * @return {number}
 */
 var singleNumber = function(nums) {
    let counts = new Object();
    for(let i = 0; i < nums.length; i++){
        if (counts[nums[i]] === undefined) counts[nums[i]] = 0;
        counts[nums[i]] ++;
        if (counts[nums[i]] >= 2) delete counts[nums[i]];
    }
    return Object.keys(counts);
};

console.log(singleNumber([2,2,1]));
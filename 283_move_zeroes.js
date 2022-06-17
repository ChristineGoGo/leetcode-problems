/**
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * Note that you must do this in-place without making a copy of the array.
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
 var moveZeroes = function(nums) {
    let [curr, next] = [0, 1];
    while ((next < nums.length) && (curr < nums.length)) {
        // console.log(`curr : ${curr}`)
        // console.log(`next : ${next}`)
        if (nums[curr]  === 0 && nums[next] !== 0) {
            nums[curr] = nums[next];
            nums[next] = 0;
            curr++;
        } else if (nums[curr] === 0 && nums[next] === 0){
            next++;
        } else {
            curr++;
            next++;
        }
        
    }
    return nums;
};
// test 1 expected[1, 0, 0]
let test1 = moveZeroes([0,0,1]);
console.log(test1);

// test 2 expected[1, 3, 12, 0, 0]
let test2 = moveZeroes([0, 1, 0, 3, 12]);
console.log(test2);

// test 3 expected[4, 1, 3, 12, 0]
let test3 = moveZeroes([4, 1, 0, 3, 12]);
console.log(test3);

// test 4 expected[4, 1, 3, 12, 0, 0]
let test4 = moveZeroes([0, 0, 4, 1, 3, 12]);
console.log(test4);


/** 
 * Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
 * Return the array in the form [x1,y1,x2,y2,...,xn,yn]. 
 * @param {number[]} nums
 * @param {number} n
 * @return {number[]}
 */

var shuffle = function(nums, n){
    let arr1 = nums.splice(0, n);
    let ans = [];
    arr1.forEach((num1, index )=> {
        const num2 = nums[index];
        ans.push(num1, num2);
    });
    return ans;
}
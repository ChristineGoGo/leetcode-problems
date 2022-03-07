/**
 * Given an integer array nums, return the third distinct maximum number in this array.
 * in chained manner
 *If the third maximum does not exist, return the maximum number.
 * @param {number[]} nums
 * @return {number}
 */

 var thirdMax = function(nums) {
    //sort nums array
    let a = nums.sort(function(a, b){return a - b});
    let [idx, distinctCount,result,n] = [nums.length - 1, 0, -1, nums.length];
    while (idx >= 0) {
        //Increment distinctCount
        distinctCount += 1;
        // Initialize i to iterate through indices having the same value as a[idx]
        i = idx - 1;
        // while the elements before idx have the same value as a[idx] and i >= 0: Decrement i
        while (i >=0 && a[idx] === a[i]) {
            i--;
        }
        //If i == -1, it means that we have traversed the whole array
        //Return a[n – 1], maximum element as there were not even 3 three distinct elements in the array
        if (i === -1){
            return a[n - 1];
        }
        // Assign idx = i to jump to next set of maximum integers
        idx = i;

        // if distictCount is 2 we have reached the third max integer return it 
        if (distinctCount === 2) {
            result = a[idx];
            return result
        }
    }
    return result;
};

//test 1 answer 2
console.log(thirdMax([2,2,3,1,4]));
//test 2 answer 1
console.log(thirdMax([2, 1, 1, 3, 2, 3]));
//test 3 answer 2
console.log(thirdMax([1,1,2]));


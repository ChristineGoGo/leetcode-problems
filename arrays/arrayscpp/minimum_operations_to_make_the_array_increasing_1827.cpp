/*
    You are given an integer array nums (0-indexed). In one operation,
    you can choose an element of the array and increment it by 1.

    For example, if nums = [1,2,3], you can choose to increment nums[1] to make nums = [1,3,3].
    Return the minimum number of operations needed to make nums strictly increasing.

    An array nums is strictly increasing if nums[i] < nums[i+1] for all 0 <= i < nums.length - 1.
    An array of length 1 is trivially strictly increasing.


    Example 1:

    Input: nums = [1,1,1]
    Output: 3
    Explanation: You can do the following operations:
    1) Increment nums[2], so nums becomes [1,1,2].
    2) Increment nums[1], so nums becomes [1,2,2].
    3) Increment nums[2], so nums becomes [1,2,3].

    Example 2:

    Input: nums = [1,5,2,4,1]
    Output: 14

    Example 3:

    Input: nums = [8]
    Output: 0

    Constraints:

    1 <= nums.length <= 5000
    1 <= nums[i] <= 10**4

*/
// APPROACH: Create a variable to store all the operations
// needed to be performed and initialize to 0. Loop through
// all the numbers in nums, if current number is greater than
// next, subtract current number - next number and add it
// to operations, set next number to equal current number + 1
// return operations
int minOperations(vector<int>& nums) {
    int operations = 0; int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        if (nums[i + 1] == nums[i]) {
            operations++;
            nums[i+1]++;
        } else if (nums[i + 1] < nums[i]) {
            operations += (nums[i] - nums[i + 1] + 1);
            nums[i + 1] = nums[i];
            nums[i + 1]++;
        }
    }
    return operations;

}


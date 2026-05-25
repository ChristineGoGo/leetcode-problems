/*
    You are given a non-negative integer array nums. In one operation, you must:

        - Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
        - Subtract x from every positive element in nums.
    Return the minimum number of operations to make every element in nums equal to 0.



    Example 1:

        Input: nums = [1,5,0,3,5]
        Output: 3
        Explanation:
        In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
        In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
        In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].

    Example 2:

        Input: nums = [0]
        Output: 0
        Explanation: Each element in nums is already 0 so no operations are needed.


    Constraints:

        1 <= nums.length <= 100
        0 <= nums[i] <= 100
*/
// APPROACH: Create variable to store the total operations
// and set the variable to 0
// Sort the numbers in ascending order
// Loop from index 0 to n:
//      - for each index, if the number isn't 0 subtract the numbers from
//          each value
//      - add the value to the operations
// return the operations
int minimumOperations(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int operations = 0;

    for (int i = 0; i < n; i ++) {
        int curr = nums[i];
        if (curr != 0) {
            for (int j = i; j < n; j++) {
                if (nums[j] != 0) nums[j] -= curr;
            }
            operations++;
        }
    }

    return operations;

}



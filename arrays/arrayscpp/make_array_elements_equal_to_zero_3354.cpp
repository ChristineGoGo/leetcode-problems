/*
    You are given an integer array nums.

    Start by selecting a starting position curr
    such that nums[curr] == 0, and choose a movement direction of either left or right.

    After that, you repeat the following process:

    If curr is out of the range [0, n - 1], this process ends.
    If nums[curr] == 0, move in the current direction by incrementing
    curr if you are moving right, or decrementing curr if you are moving left.
    Else if nums[curr] > 0:
    Decrement nums[curr] by 1.
    Reverse your movement direction (left becomes right and vice versa).
    Take a step in your new direction.
    A selection of the initial position curr and movement direction is considered
    valid if every element in nums becomes 0 by the end of the process.

    Return the number of possible valid selections.

    

    Example 1:

    Input: nums = [1,0,2,0,3]

    Output: 2

    Explanation:

    The only possible valid selections are the following:

    Choose curr = 3, and a movement direction to the left.
    [1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,1,0,3] -> [1,0,1,0,3] -> 
    [1,0,1,0,2] -> [1,0,1,0,2] -> [1,0,0,0,2] -> [1,0,0,0,2] -> [1,0,0,0,1] -> [1,0,0,0,1] -> 
    [1,0,0,0,1] -> [1,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,0].
    Choose curr = 3, and a movement direction to the right.
    [1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,2,0,2] -> [1,0,2,0,2] -> [1,0,1,0,2] -> [1,0,1,0,2] -> 
    [1,0,1,0,1] -> [1,0,1,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [0,0,0,0,0].
    Example 2:

    Input: nums = [2,3,4,0,4,1,0]

    Output: 0

    Explanation:

    There are no possible valid selections.

    

    Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 100
    There is at least one element i where nums[i] == 0.

*/
#include <iostream>
using namespace std;

// APPROACH: Use the prefix and suffix sum method
int countValidSelections(vector<int>& nums) {
    int totalSum = 0;
    int valid = 0;
    int n = nums.size();

    vector<int> leftSum(n, 0);
    vector<int> rightSum(n, 0);

    for (int num: nums) { totalSum += num;}

    // populate array with all the sums to the right
    for (int i = 0; i < n; i++) {
        rightSum[i] = totalSum - nums[i];
        totalSum = rightSum[i];
    }
    totalSum = 0;
    // populate array with all the sums to the left
    for (int i = 0; i < n; i++) {
        leftSum[i] += totalSum;
        totalSum +=  nums[i];
    }

    // go over nums to find nums[i] that is 0 and that balances
    // with equal sums on each side or a difference of 1

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            if (leftSum[i] == rightSum[i]) {
                valid += 2;
            } else if ( abs(leftSum[i] - rightSum[i]) == 1) {
                valid++;
            }
        }
    }

    return valid;


}








/*

    Given an array nums sorted in non-decreasing order, return the maximum between the number of positive
    integers and the number of negative integers.

    In other words, if the number of positive integers in nums is pos and the number of negative integers is
    neg, then return the maximum of pos and neg.
    Note that 0 is neither positive nor negative.


    Example 1:

    Input: nums = [-2,-1,-1,1,2,3]
    Output: 3
    Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.

    Example 2:

    Input: nums = [-3,-2,-1,0,0,1,2]
    Output: 3
    Explanation: There are 2 positive integers and 3 negative integers. The maximum count among them is 3.


    Example 3:

    Input: nums = [5,20,66,1314]
    Output: 4
    Explanation: There are 4 positive integers and 0 negative integers. The maximum count among them is 4.


    Constraints:

    1 <= nums.length <= 2000
    -2000 <= nums[i] <= 2000
    nums is sorted in a non-decreasing order.


    Follow up: Can you solve the problem in O(log(n)) time complexity?

*/

// APPROACH: Create two functions to find the first 0 or positive
// this function is used to find the number of negative values to left of index(lowerBound)
// Second function is used to find the first positive this is used to find
// the number of positive values which will be to the right of the index(upperBound)
// return the max of the two values
int lowerBound(vector<int> nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0 || nums[i] > 0) {
            return i;
        }
    }
    return n;
}

int upperBound(vector<int> nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            return n - i;
        }
    }
    return 0;

}
int maximumCount(vector<int>& nums) {
    if (nums.size() == 1 && nums[0] != 0) return 1;
    return max(lowerBound(nums), upperBound(nums));
}


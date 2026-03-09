/*
    Given an array of positive integers nums, return the maximum possible sum of an strictly
    increasing subarray in nums.

    A subarray is defined as a contiguous sequence of numbers in an array.


    Example 1:
    Input: nums = [10,20,30,5,10,50]
    Output: 65
    Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.

    Example 2:
    Input: nums = [10,20,30,40,50]
    Output: 150
    Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.

    Example 3:
    Input: nums = [12,17,15,13,10,11,12]
    Output: 33
    Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.

    Constraints:

    1 <= nums.length <= 100
    1 <= nums[i] <= 100
*/

// APPROACH: Create a variable to store the result
// Create a varible to store the current starting index
// and another one to store the ending index
// Loop while the ending index is less than the length of nums
//  - find the sum of each iteration
//  - stop looping when the subarray is not increasing
//  - set the current sum to maximum possible sum if it is bigger
//    than the maximum sum on hand already
int maxAscendingSum(vector<int>& nums) {
    int n = nums.size();
    int maxSum = nums[0]; int start = 0; int end = 1;
    int curr = maxSum;

    while ( end < n) {
        if (nums[end] > nums[start]) {
            // cout << "subarray is increasing : " << "\n";
            // cout << "ending number is " << nums[end] << "\n";
            // cout << "starting number is " << nums[start] << "\n";
            curr += nums[end];
            // cout << "current sum is: " << curr << "\n";
            start++;
            end++;
        } else {
            // cout << "not increasing anymore";
            maxSum = max(maxSum, curr);
            // cout << "total found sum: " << maxSum << "\n";
            curr = nums[end];
            start = end;
            end++;
        }
    }
    return maxSum > curr ? maxSum : curr;

}







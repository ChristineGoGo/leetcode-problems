/*
    Given the array nums, obtain a subsequence of the array whose sum of
    elements is strictly greater than the sum of the non included elements in such subsequence.

    If there are multiple solutions, return the subsequence with minimum size and if there still
    exist multiple solutions, return the subsequence with the maximum total sum of all its elements.
    A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array.

    Note that the solution with the given constraints is guaranteed to be unique. Also return the answer
    sorted in non-increasing order.

    Example 1:

    Input: nums = [4,3,10,9,8]
    Output: [10,9] 
    Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements
    is strictly greater than the sum of elements not included. However, the subsequence [10,9] has
    the maximum total sum of its elements.

    Example 2:
    Input: nums = [4,4,7,6,7]
    Output: [7,7,6]
    Explanation: The subsequence [7,7] has the sum of its elements equal to 14 which
    is not strictly greater than the sum of elements not included (14 = 4 + 4 + 6).
    Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions.
    Note the subsequence has to be returned in non-increasing order.


    Constraints:

    1 <= nums.length <= 500
    1 <= nums[i] <= 100
*/

// APPROACH: Create results array
// Sort nums array in ascending order
// Find the total sum of all the numbers in nums
// Create variable called current running total
// Loop from index n - 1:
//  - Add current number to results array
//  - subtract current number from total sum.
//  - Add current number to total running sum
//  - check if current running total is greater than total sum.
//      - if greater, return results array
// Return results array
vector<int> minSubsequence(vector<int>& nums) {
    vector<int> results;
    sort(nums.begin(), nums.end());
    int totSum = 0; int totRunningSum = 0; int n = nums.size();

    for (int num: nums) {
        totSum += num;
    }

    for (int i = n - 1; i >= 0; i--) {
        results.push_back(nums[i]);
        totSum -= nums[i];
        totRunningSum += nums[i];
        if (totRunningSum > totSum) return results;
    }
    return results;


}





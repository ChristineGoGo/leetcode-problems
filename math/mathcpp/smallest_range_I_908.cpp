/*

    You are given an integer array nums and an integer k.

    In one operation, you can choose any index i where 0 <= i
    < nums.length and change nums[i] to nums[i] + x where x is
    an integer from the range [-k, k]. You can apply this operation
    at most once for each index i.

    The score of nums is the difference between the maximum and
    minimum elements in nums.

    Return the minimum score of nums after applying the mentioned
    operation at most once for each index in it.

    

    Example 1:

    Input: nums = [1], k = 0
    Output: 0
    Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
    Example 2:

    Input: nums = [0,10], k = 2
    Output: 6
    Explanation: Change nums to be [2, 8]. The score is max(nums) - min(nums) = 8 - 2 = 6.
    Example 3:

    Input: nums = [1,3,6], k = 3
    Output: 0
    Explanation: Change nums to be [4, 4, 4]. The score is max(nums) - min(nums) = 4 - 4 = 0.
    

    Constraints:

    1 <= nums.length <= 104
    0 <= nums[i] <= 104
    0 <= k <= 104
*/
#include <iostream>

using namespace std;

int smallestRangeI(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int minNum = nums[0] + k;
    int maxNum = nums[n - 1] - k;
    int ans = (maxNum - minNum ) <=  0 ? 0 : (maxNum - minNum);
    return ans;
    
}
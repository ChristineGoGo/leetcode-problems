/*
    Given an integer array nums, return the number of subarrays of length 3 such that the sum
    of the first and third numbers equals exactly half of the second number.

    

    Example 1:

    Input: nums = [1,2,1,4,1]

    Output: 1

    Explanation:

    Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third
    numbers equals half the middle number.

    Example 2:

    Input: nums = [1,1,1]

    Output: 0

    Explanation:

    [1,1,1] is the only subarray of length 3. However, its first and third numbers do not add to half the middle number.

    

    Constraints:

    3 <= nums.length <= 100
    -100 <= nums[i] <= 100

*/

#include <iostream>
using namespace std;

// APPROACH: Use linear search to find the sum of the first and third numbers
//  then figuring out if that sum is half the second numbers
int countSubarrays(vector<int>& nums) {
    int total = 0;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        double sum = nums[i] + nums[i + 2];
        double half = nums[i + 1] / 2.0;

        if (sum == half) {
            total++;
        }

    }

    return total;
}





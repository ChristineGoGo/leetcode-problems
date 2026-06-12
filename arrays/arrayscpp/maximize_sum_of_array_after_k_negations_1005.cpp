/*
    Given an integer array nums and an integer k, modify the array in the following way:

        choose an index i and replace nums[i] with -nums[i].
        You should apply this process exactly k times. You may choose the same index i multiple times.

    Return the largest possible sum of the array after modifying it in this way.



    Example 1:

        Input: nums = [4,2,3], k = 1
        Output: 5
        Explanation: Choose index 1 and nums becomes [4,-2,3].

    Example 2:

        Input: nums = [3,-1,0,2], k = 3
        Output: 6
        Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].

    Example 3:

        Input: nums = [2,-3,-1,5,-4], k = 2
        Output: 13
        Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].


    Constraints:

        1 <= nums.length <= 10**4
        -100 <= nums[i] <= 100
        1 <= k <= 10**4

*/


// APPROACH: Create a variable to store the result sum
// Sort nums in ascending order
// Set all negative indices to positive for each k
// if k >= n:
//      - if k % 2 is not 0 sort nums again and set first
//         value to equal to value * -1
// Return the sum of the resulting sorted nums
int largestSumAfterKNegations(vector<int>& nums, int k) {
    int totSum = 0; int n = nums.size(); int idx = 0;
    sort(nums.begin(), nums.end());

    while (k > 0 && idx < n ) {
        if (nums[idx] < 0) {
            nums[idx] *= -1;
            k--;
        } else if (nums[idx] == 0) {
            break;
        }
        idx++;
    }

    if (k > 0) {
        sort(nums.begin(), nums.end());

        if (k % 2 != 0) {
            nums[0] *= -1;
        }

    }


    for (int i = 0; i < n; i++) {
        totSum += nums[i];
    }

    return totSum;
}




/*
    We define a harmonious array as an array where the difference
    between its maximum value and its minimum value is exactly 1.

    Given an integer array nums, return the length of its longest
    harmonious subsequence among all its possible subsequences.



    Example 1:

    Input: nums = [1,3,2,2,5,2,3,7]

    Output: 5

    Explanation:

    The longest harmonious subsequence is [3,2,2,2,3].

    Example 2:

    Input: nums = [1,2,3,4]

    Output: 2

    Explanation:

    The longest harmonious subsequences are [1,2], [2,3], and [3,4],
    all of which have a length of 2.

    Example 3:

    Input: nums = [1,1,1,1]

    Output: 0

    Explanation:

    No harmonic subsequence exists.



    Constraints:

    1 <= nums.length <= 2 * 104
    -109 <= nums[i] <= 109



*/

// APPROACH: Sort nums from smallest to largest
// use a variable to track the longest harmonious subsequence
// loop from the first number in nums (i) to the last number(j)
// if nums[j] - nums[i] = 1, reevaluate the longest harmonious
// subsequent. Return the longest harmonious subsequence found after the iteration

int findLHS(vector<int>& nums) {
    stable_sort(nums.begin(), nums.end());
    int n = nums.size(), longest = 0;

    for (int i = 0; i < n; i++) {
        for(int j = n - 1;j >= 0; j--) {
            int curr = nums[j] - nums[i];
            if (curr == 1 ){
                longest = max(j - i + 1, longest);
            }
        }
    }

    return longest;

}









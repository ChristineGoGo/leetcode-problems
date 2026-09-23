/*
    You are given an integer array nums of odd length n.

    Return true if the middle element of nums appears exactly
    once in the array. Otherwise return false.


    Example 1:

        Input: nums = [1,2,3]

        Output: true

        Explanation:

        The middle element of nums is 2, which appears exactly once.

        Thus, the answer is true.

    Example 2:

        Input: nums = [1,2,2]

        Output: false

        Explanation:

        The middle element of nums is 2, which appears twice.

        Thus, the answer is false.


    Constraints:

        1 <= n == nums.length <= 100
        n is odd.
        1 <= nums[i] <= 100

*/

// APPROACH: Use hashmap to figure the frequency of each element
// Return if n(size of nums) freq[nums[n / 2]] == 1
bool isMiddleElementUnique(vector<int>& nums) {
    map<int, int> freq;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }

    return freq[nums[n / 2]] == 1;

}


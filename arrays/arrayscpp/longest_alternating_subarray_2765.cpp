/*
    You are given a 0-indexed integer array nums. A subarray s of length m is called alternating if:

        - m is greater than 1.
        - s1 = s0 + 1.
        - The 0-indexed subarray s looks like [s0, s1, s0, s1,...,s(m-1) % 2]. In other words,
        s1 - s0 = 1, s2 - s1 = -1, s3 - s2 = 1, s4 - s3 = -1, and so on up to s[m - 1] - s[m - 2] = (-1)m.

    Return the maximum length of all alternating subarrays present in nums or -1 if no such subarray exists.

    A subarray is a contiguous non-empty sequence of elements within an array.


    Example 1:

        Input: nums = [2,3,4,3,4]

        Output: 4

        Explanation:

        The alternating subarrays are [2, 3], [3,4], [3,4,3], and [3,4,3,4]. The longest of these is [3,4,3,4], which is of length 4.

    Example 2:

        Input: nums = [4,5,6]

        Output: 2

        Explanation:

        [4,5] and [5,6] are the only two alternating subarrays. They are both of length 2.


    Constraints:

        2 <= nums.length <= 100
        1 <= nums[i] <= 104

*/

// APPROACH: Create variable to store the longest
// alternating sequence and set it to -1
// Create a variable dir that stores the decision
// whether the current alternating sequence continues
// Loop for each number in nums:
//      - follow the sequence of s1 - s0 = 1
//        s2 - s1 = -1 etc...
//      - add to running count each time there
//        is a sequence
//      - update the longest alternating variable
// Return the longest alternating variable
int alternatingSubarray(vector<int>& nums) {
    int longest = -1; int n = nums.size();
    int dir = 1; int count = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] - nums[i - 1] == dir) {
            count++;
            longest = max(longest,count);
            dir *= -1;
        } else {
            if(nums[i] - nums[i - 1] == 1) {
                dir = -1;
                count = 2;
            }else {
                count = 1;
                dir = 1;
            }
        }
    }

    return longest;

}




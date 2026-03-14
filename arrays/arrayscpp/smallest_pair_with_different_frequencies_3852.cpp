/*
    You are given an integer array nums.

    Consider all pairs of distinct values x and y from nums such that:

        - x < y
        - x and y have different frequencies in nums.

    Among all such pairs:

        - Choose the pair with the smallest possible value of x.
        - If multiple pairs have the same x, choose the one with the smallest possible value of y.
    Return an integer array [x, y]. If no valid pair exists, return [-1, -1].


    Example 1:

        Input: nums = [1,1,2,2,3,4]

        Output: [1,3]

        Explanation:

        The smallest value is 1 with a frequency of 2, and the smallest value greater
        than 1 that has a different frequency from 1 is 3 with a frequency of 1. Thus,
        the answer is [1, 3].

    Example 2:

    Input: nums = [1,5]

    Output: [-1,-1]

    Explanation:

    Both values have the same frequency, so no valid pair exists. Return [-1, -1].

    Example 3:

    Input: nums = [7]

    Output: [-1,-1]

    Explanation:

    There is only one value in the array, so no valid pair exists. Return [-1, -1].



    Constraints:

    1 <= nums.length <= 100
    1 <= nums[i] <= 100

*/

// APPROACH: Create map to store the frequency of each # in nums
// Create set to store the numbers in ascending number
// Find the required pair and return
vector<int> minDistinctFreqPair(vector<int>& nums) {
    vector<int> result;
    set<int> numbers;
    map<int, int> freqs;

    sort(nums.begin(), nums.end());

    for (int num: nums) {
        numbers.insert(num);
        freqs[num]++;
    }

    result.push_back(nums[0]);

    for (int num: numbers) {
        if (freqs[nums[0]] != freqs[num]) {
            result.push_back(num);
            break;
        }
    }

    if (result.size() == 2) return result;

    return {-1, -1};

}



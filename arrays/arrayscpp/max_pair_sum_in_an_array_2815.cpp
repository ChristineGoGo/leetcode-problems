/*
    You are given an integer array nums. You have to find the maximum sum of a pair
    of numbers from nums such that the largest digit in both numbers is equal.

    For example, 2373 is made up of three distinct digits: 2, 3, and 7, where 7 is the largest among them.

    Return the maximum sum or -1 if no such pair exists.


    Example 1:

        Input: nums = [112,131,411]

        Output: -1

        Explanation:

        Each numbers largest digit in order is [2,3,4].

    Example 2:

        Input: nums = [2536,1613,3366,162]

        Output: 5902

        Explanation:

        All the numbers have 6 as their largest digit, so the answer is 2536 + 3366 = 5902.

    Example 3:

        Input: nums = [51,71,17,24,42]

        Output: 88

        Explanation:

            Each number's largest digit in order is [5,7,7,4,4].

            So we have only two possible pairs, 71 + 17 = 88 and 24 + 42 = 66.


    Constraints:

        2 <= nums.length <= 100
        1 <= nums[i] <= 10**4

*/

// APPROACH: Create a map to store each number
// and the largest digit in the number
// Loop for each number in nums:
//  - Find the pairs with the same largest digits
//  - add the pair
//  - update maximum pair

int maxSum(vector<int>& nums) {
    map<int, int> mp;
    map<int, int> countBiggest;
    sort(nums.begin(), nums.end());
    int maxNum = 0;

    for(int num: nums) {
        string curr = to_string(num);
        int currNum = 0;
        sort(curr.begin(), curr.end());
        string s = "";
        s += curr[curr.size() - 1];
        int biggest = stoi(s);
        mp[num] = biggest;
    }


    vector<int> b;
    int currSum = 0;
    int maxSum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mp[nums[i]] == mp[nums[j]]) {
                currSum = nums[i] + nums[j];
                maxSum = max(currSum, maxSum);
            }
        }
    }

    return maxSum > 0? maxSum: -1;

}


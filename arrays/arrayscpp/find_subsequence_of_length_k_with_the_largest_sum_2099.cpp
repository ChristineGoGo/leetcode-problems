/*

    You are given an integer array nums and an integer k.
    You want to find a subsequence of nums of length k that has the largest sum.

    Return any such subsequence as an integer array of length k.

    A subsequence is an array that can be derived from another array by deleting
    some or no elements without changing the order of the remaining elements.


    Example 1:

        - Input: nums = [2,1,3,3], k = 2
        - Output: [3,3]
        - Explanation:
          The subsequence has the largest sum of 3 + 3 = 6.
    Example 2:

        - Input: nums = [-1,-2,3,4], k = 3
        - Output: [-1,3,4]
        - Explanation: 
        - The subsequence has the largest sum of -1 + 3 + 4 = 6.

    Example 3:

        - Input: nums = [3,4,3,3], k = 2
        - Output: [3,4]
        - Explanation:
        - The subsequence has the largest sum of 3 + 4 = 7.
          Another possible subsequence is [4, 3].


    Constraints:

        - 1 <= nums.length <= 1000
        - 10 ** 5 <= nums[i] <= 10 ** 5
        - 1 <= k <= nums.length

*/
#include <iostream>
#include <vector>
#include <map>


using namespace std;

// APPROACH: Use a map with boolean values to store the
// order of the numbers with the largest sum
vector<int> maxSubsequence(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> lSum;
    vector<int> result;
    vector<int> indices;
    map<int, vector<int>> freqOrd;

    for (int i = 0; i < n; i++) {
        freqOrd[i].push_back(nums[i]);
        freqOrd[i].push_back(0);
    }

    sort(nums.begin(), nums.end());

    for (int i = n - k; i < n; i++) {
        int sIdx = 0;
        for (auto& vals: freqOrd) {
            vector<int> curr = vals.second;

            if (nums[i] == curr[0] && curr[1] == 0) {
                vals.second.pop_back();
                vals.second.push_back(1);
                indices.push_back(sIdx);
                break;
            }
            sIdx++;
        }
    }

    for (auto vals: freqOrd) {
        vector<int> curr = vals.second;

        if (curr[1] == 1) {
            result.push_back(curr[0]);
        }
    }

    return result;

}

int main() {
    vector<int> z = {1,3, 4, 4};
    maxSubsequence(z, 2);
}


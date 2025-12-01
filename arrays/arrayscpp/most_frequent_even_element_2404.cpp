/*


    Given an integer array nums, return the most frequent even element.

    If there is a tie, return the smallest one. If there is no such element, return -1.

    

    Example 1:

    Input: nums = [0,1,2,2,4,4,1]
    Output: 2
    Explanation:
    The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
    We return the smallest one, which is 2.
    Example 2:

    Input: nums = [4,4,4,9,2,4]
    Output: 4
    Explanation: 4 is the even element appears the most.
    Example 3:

    Input: nums = [29,47,21,41,13,37,25,7]
    Output: -1
    Explanation: There is no even element.
    

    Constraints:

    1 <= nums.length <= 2000
    0 <= nums[i] <= 10**5
*/
#include <iostream>
using namespace std;

// APPROACH: Sort nums in ascending order 
// create map to store the frequency of each number in nums
// loop through nums, if number is even return its frequency since it is smallest
// if there isn't an even number return -1

int mostFrequentEven(vector<int>& nums) {
    stable_sort(nums.begin(), nums.end());
    map<int, int> freq;
    set<int> s;
    int n = nums.size();
    int biggest = 0;

    // find frequencies
    for (int num: nums) {
        freq[num]++;
    }

    // find the most frequent
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] % 2 == 0 ) {
            biggest = max(biggest, freq[nums[i]]);
        }
    }

    // find the smallest frequent number
    for (int i = 0; i < n; i++) {
        if (freq[nums[i]] == biggest && nums[i] % 2 == 0) {
            return nums[i];
        }
    }

    return -1;

    
}



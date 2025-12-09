/*

    You are given an array nums, where each number in the array appears either once or twice.

    Return the bitwise XOR of all the numbers that appear twice in the array, or 0 if no number appears twice.


    Example 1:

    Input: nums = [1,2,1,3]

    Output: 1

    Explanation:

    The only number that appears twice in nums is 1.

    Example 2:

    Input: nums = [1,2,3]

    Output: 0

    Explanation:

    No number appears twice in nums.

    Example 3:

    Input: nums = [1,2,2,1]

    Output: 3

    Explanation:

    Numbers 1 and 2 appeared twice. 1 XOR 2 == 3.


    Constraints:

    1 <= nums.length <= 50
    1 <= nums[i] <= 50
    Each number in nums appears either once or twice.

*/

#include <iostream>

using namespace std;

// APPROACH: Create a hashmap that stores all the numbers and their frequencies
// create a vectore that will store all the numbers that appear twice
// find the xor of all the numbers that appear twice
// return 0 if size of vector is zero else return the calculated xor

int duplicateNumbersXOR(vector<int>& nums) {
    map<int, int> freq;
    vector<int> twice;

    for (int num: nums) {
        freq[num]++;
    }

    for (auto vals: freq) {
        if(vals.second == 2) {
            twice.push_back(vals.first);
        }
    }

    int x = 0;

    for (int num: twice) {
        x ^= num;
    }

    return twice.size() == 0 ? 0 : x;

}




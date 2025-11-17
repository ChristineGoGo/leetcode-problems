/*
    Given an binary array nums and an integer k, return true 
    if all 1's are at least k places away from each other, otherwise return false.

    

    Example 1:


    Input: nums = [1,0,0,0,1,0,0,1], k = 2
    Output: true
    Explanation: Each of the 1s are at least 2 places away from each other.
    Example 2:


    Input: nums = [1,0,0,1,0,1], k = 2
    Output: false
    Explanation: The second 1 and third 1 are only one apart from each other.
    

    Constraints:

    1 <= nums.length <= 105
    0 <= k <= nums.length
    nums[i] is 0 or 1

*/

#include <iostream>
using namespace std;


// APPROACH: Loop for each number in nums, if number is 
// 1 loop to the end of the array until another 1 is found
// if is less than k return false. Return true after the loop
bool kLengthApart(vector<int>& nums, int k) {
    vector<int> res;
    int n = nums.size();

    if (k == 0) {
        if (nums[1] == 1 && nums[0] == 1) return true;
    }
    

    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            int start = i + 1;

            while (start < n) {
                if (nums[start] == 1) {
                    int curr = start - i - 1;
                    if (curr < k) return false;
                }
                start++;
            }
        }
    }


    return true;
    
}






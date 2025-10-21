/*

    Given an integer array nums and an integer k, 
    return the smallest positive multiple of k that is missing from nums.

    A multiple of k is any positive integer divisible by k.

    

    Example 1:

    Input: nums = [8,2,3,4,6], k = 2

    Output: 10

    Explanation:

    The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest
    multiple missing from nums is 10.

    Example 2:

    Input: nums = [1,4,7,10,15], k = 5

    Output: 5

    Explanation:

    The multiples of k = 5 are 5, 10, 15, 20... and the smallest multiple missing from nums is 5.

    

    Constraints:

    1 <= nums.length <= 100
    1 <= nums[i] <= 100
    1 <= k <= 100

*/
#include <iostream>
using namespace std;


// APPROACH: Sort the given vector in asceding order
// Use a variable to track the multiplier 
//  used to find the current multiple of k. Loop
// while the multiple is available in nums. If it is not,
// exit the loop early and return the missing multiple
int missingMultiple(vector<int>& nums, int k) {
    int multiplier = 1;
    int multipleAvailable = 1;
    int currMul;

    sort(nums.begin(), nums.end());

    while (multipleAvailable == 1) {
        currMul = k * multiplier;
        int found = 0;

        for (int num: nums) {
            if (num == currMul) {
                multipleAvailable = 1;
                found = 1;
                break;
            }
        }

        if (found == 0 ) {
            multipleAvailable = 0;
            return currMul;
        }

        multiplier++;

    }

    return currMul;

    
}



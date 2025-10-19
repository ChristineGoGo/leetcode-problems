/*

    You are given an integer array nums.

    You are allowed to delete any number of elements from 
    nums without making it empty. After performing the deletions,
    select a subarray of nums such that:

    All elements in the subarray are unique.
    The sum of the elements in the subarray is maximized.
    Return the maximum sum of such a subarray.

    

    Example 1:

    Input: nums = [1,2,3,4,5]

    Output: 15

    Explanation:

    Select the entire array without deleting any element to obtain the maximum sum.

    Example 2:

    Input: nums = [1,1,0,1,1]

    Output: 1

    Explanation:

    Delete the element nums[0] == 1, nums[1] == 1, nums[2] == 0, and
    nums[3] == 1. Select the entire array [1] to obtain the maximum sum.

    Example 3:

    Input: nums = [1,2,-1,-2,1,0,-1]

    Output: 3

    Explanation:

    Delete the elements nums[2] == -1 and nums[3] == -2, and select the 
    subarray [2, 1] from [1, 2, 1, 0, -1] to obtain the maximum sum.

    

    Constraints:

    1 <= nums.length <= 100
    -100 <= nums[i] <= 100
*/

#include <iostream>
#include <map>
#include <set>


using namespace std;

// APPROACH: Sort the given array. If there is a positive number, delete
// all negatives, else put all numbers in a set and find the sum
int maxSum(vector<int>& nums) {
    set<int> nNums;
    map<int, int> freq;
    int total = 0;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int start = n - 1;
    int foundNeg = 0;

    // remove duplicates and negatives if needed
    while (start > 0) {
        if (foundNeg == 0) {
            nNums.insert(nums[start]);
        } else {
            break;
        }
        foundNeg = nums[start - 1] > 0 ? 0 : 1;
        start--;

    }
    if (foundNeg == 0) nNums.insert(nums[0]);

    for (int num: nNums) {
        total += num;
    }
    
    return total;
}












/*
    You are given an integer array nums.

    Return the smallest absent positive integer
    in nums such that it is strictly greater than 
    the average of all elements in nums.

    The average of an array is defined as the sum of
    all its elements divided by the number of elements.
    

    Example 1:

    Input: nums = [3,5]

    Output: 6

    Explanation:

    The average of nums is (3 + 5) / 2 = 8 / 2 = 4.
    The smallest absent positive integer greater than 4 is 6.
    Example 2:

    Input: nums = [-1,1,2]

    Output: 3

    Explanation:

    ​​​​​​​The average of nums is (-1 + 1 + 2) / 3 = 2 / 3 = 0.667.
    The smallest absent positive integer greater than 0.667 is 3.
    Example 3:

    Input: nums = [4,-1]

    Output: 2

    Explanation:

    The average of nums is (4 + (-1)) / 2 = 3 / 2 = 1.50.
    The smallest absent positive integer greater than 1.50 is 2.
    

    Constraints:

    1 <= nums.length <= 100
    -100 <= nums[i] <= 100​​​​​​​

*/
#include <iostream>
using namespace std;

// APPROACH: Find the average. Find the greater
// number missing from nums
int smallestAbsent(vector<int>& nums) {
    int total = 0;
    int n = nums.size();
    int absent = 0;

    stable_sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        total += nums[i];
    }

    double average = total / n;
    double currAbsent = average > 0 ? average + 1 : 1;
    

    for (int i = 0; i < n; i++) {
        if (nums[i] == currAbsent) {
            currAbsent++;
        }

    }

    return currAbsent;
    
}





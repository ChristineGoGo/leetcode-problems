/*
    Given an array of integers nums, sort the array in increasing 
    order based on the frequency of the values. If multiple values 
    have the same frequency, sort them in decreasing order.

    Return the sorted array.

    

    Example 1:

    Input: nums = [1,1,2,2,2,3]
    Output: [3,1,1,2,2,2]
    Explanation: '3' has a frequency of 1, '1' has a frequency of 2, 
    and '2' has a frequency of 3.
    Example 2:

    Input: nums = [2,3,1,3,2]
    Output: [1,3,3,2,2]
    Explanation: '2' and '3' both have a frequency of 2, so they are sorted
    in decreasing order.
    Example 3:

    Input: nums = [-1,1,-6,4,5,-6,1,4,1]
    Output: [5,-1,4,4,-6,-6,1,1,1]
    

    Constraints:

    1 <= nums.length <= 100
    -100 <= nums[i] <= 100

*/
#include <iostream>
#include <map>

using namespace std;
// APPROACH: Find the frequencies of each number in 
// nums. Sort according to the increasing frequencies using a
// lambda function
vector<int> frequencySort(vector<int>& nums) {
    map<int, int> freqTracker;
    

    // find the frequencies of each value
    for (int num: nums) {
        freqTracker[num]++;
    }

    // sort nums according to the frequencies separately
    sort(nums.begin(), nums.end(),[&](int a, int b){
        if (freqTracker[a] == freqTracker[b]) {
            return a > b;
        }
        return freqTracker[a] < freqTracker[b];
    });

    return nums;
}




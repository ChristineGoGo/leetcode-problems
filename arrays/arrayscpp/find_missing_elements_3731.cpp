/*

    You are given an integer array nums consisting of unique integers.

    Originally, nums contained every integer within a certain range. 
    However, some integers might have gone missing from the array.

    The smallest and largest integers of the original range are still
    present in nums.

    Return a sorted list of all the missing integers in this range.
    If no integers are missing, return an empty list.

    

    Example 1:

    Input: nums = [1,4,2,5]

    Output: [3]

    Explanation:

    The smallest integer is 1 and the largest is 5, so the full 
    range should be [1,2,3,4,5]. Among these, only 3 is missing.

    Example 2:

    Input: nums = [7,8,6,9]

    Output: []

    Explanation:

    The smallest integer is 6 and the largest is 9, so the full
    range is [6,7,8,9]. All integers are already present, so no integer is missing.

    Example 3:

    Input: nums = [5,1]

    Output: [2,3,4]

    Explanation:

    The smallest integer is 1 and the largest is 5, so the full
    range should be [1,2,3,4,5]. The missing integers are 2, 3, and 4.

*/


#include <iostream>
using namespace std;

// APPROACH: Sort nums and assign vector result,
// loop from 1 until 100 when reaching the smallest loop until the biggest digit
// adding missing nums to result
vector<int> findMissingElements(vector<int>& nums) {
    stable_sort(nums.begin(), nums.end());
    vector<int> result;

    int n = nums.size();
    int small =nums[0];
    int big = nums[n - 1];
    int found = 0;
    

    for (int i = 0; i < 100; i++) {
        int found = 0;

        if (i > small && i < big) {
            for (int num: nums) {
                if (num == i ) {
                    found = 1;
                    break;
                }   
            }
            if (found == 0) result.push_back(i);
        } else if( i == big) {
            break;
        }
    }

    return result;
    
}

int main() {
    vector<int> m = {9, 0, 8, 7}
}






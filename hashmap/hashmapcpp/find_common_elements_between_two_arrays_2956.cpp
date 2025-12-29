/*
    You are given two integer arrays nums1 and nums2 of sizes n and m,
    respectively. Calculate the following values:

    answer1 : the number of indices i such that nums1[i] exists in nums2.
    answer2 : the number of indices i such that nums2[i] exists in nums1.
    Return [answer1,answer2].

    

    Example 1:

    Input: nums1 = [2,3,2], nums2 = [1,2]

    Output: [2,1]

    Explanation:



    Example 2:

    Input: nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6]

    Output: [3,4]

    Explanation:

    The elements at indices 1, 2, and 3 in nums1 exist in nums2 as well. So answer1 is 3.

    The elements at indices 0, 1, 3, and 4 in nums2 exist in nums1. So answer2 is 4.

    Example 3:

    Input: nums1 = [3,4,2,3], nums2 = [1,5]

    Output: [0,0]

    Explanation:

    No numbers are common between nums1 and nums2, so answer is [0,0].

    

    Constraints:

    n == nums1.length
    m == nums2.length
    1 <= n, m <= 100
    1 <= nums1[i], nums2[i] <= 100

*/
// APPROACH: Use two arrays to determine the numbers in
// nums1 that exist in nums2 and in nums2 that exist in
// nums1 and return the total in a results array
#include <iostream>
#include <vector>

using namespace std;



vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();


    int found = 0;
    vector<int> results;
    
    

    for (int i = 0; i < n;i++) {
        int total = 0;
        for (int num: nums2) {
            if (num == nums1[i]) {
                total++;
                break;
            }
        }
        if (total > 0) {
            found++;
        }
    }
    results.push_back(found);

    found = 0;
    for (int i = 0; i < m;i++) {
        int total = 0;
        for (int num: nums1) {
            if (num == nums2[i]) {
                total++;
                break;
            }
        }

        if (total > 0) {
            found++;
        }
    }

    results.push_back(found);


    return results;
    
}





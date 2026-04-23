/*

    Given two integer arrays nums1 and nums2, sorted in non-decreasing order,
    return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

    Note that an integer is said to be common to nums1 and nums2 if both
    arrays have at least one occurrence of that integer.



    Example 1:

        Input: nums1 = [1,2,3], nums2 = [2,4]
        Output: 2
        Explanation: The smallest element common to both arrays is 2, so we return 2.

    Example 2:

        Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
        Output: 2
        Explanation: There are two common elements in the array 2 and 3 out of which
        2 is the smallest, so 2 is returned.

    Constraints:

        1 <= nums1.length, nums2.length <= 10**5
        1 <= nums1[i], nums2[j] <= 10 ** 9
        Both nums1 and nums2 are sorted in non-decreasing order.


*/

// APPROACH:
// Since the numbers are sorted in non decreasing order,
// Use two pointers to control the index of each number
// compare equality and move forwad as needed
// Always return -1 if there is no common number.

int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int idx1 = 0; int idx2 = 0;
    int n = nums1.size(); int m = nums2.size();

    while (idx1 < n && idx2 < m) {
        // Keep searching nums 1
        if (nums1[idx1] < nums2[idx2]) {
            idx1++;
            // Keep searching nums 2
        } else if (nums1[idx1] > nums2[idx2]) {
            idx2++;
        } else {
            return nums1[idx1];
        }
    }
    return -1;

}




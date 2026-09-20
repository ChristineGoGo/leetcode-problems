/*
    Given two arrays of unique digits nums1 and nums2,
    return the smallest number that contains at least one digit from each array.


    Example 1:
        Input: nums1 = [4,1,3], nums2 = [5,7]
        Output: 15
        Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2.
        It can be proven that 15 is the smallest number we can have.

    Example 2:

        Input: nums1 = [3,5,2,6], nums2 = [3,1,7]
        Output: 3
        Explanation: The number 3 contains the digit 3 which exists in both arrays.


    Constraints:
        1 <= nums1.length, nums2.length <= 9
        1 <= nums1[i], nums2[i] <= 9
        All digits in each array are unique.
*/

// APPROACH: Determine if nums1 and nums2
// contain the same digits and return the smallest
// Sort nums1 and nums2 in ascending order
// multiply first number by 10 and add second number to form 2 digits
// Return the resulting sum
int minNumber(vector<int>& nums1, vector<int>& nums2) {
    int smallest = 9; bool pair = false;
    for (int num1: nums1) {
        for (int num2: nums2) {
            if (num1 == num2) {
                smallest = min(smallest, num1);
                pair = true;
            }
        }
    }

    if (pair) return smallest;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());


    int num1 = nums1[0] < nums2[0] ? nums1[0] : nums2[0];
    int num2 = nums1[0] > nums2[0] ? nums1[0] : nums2[0];

    return (num1 * 10) + num2;

}



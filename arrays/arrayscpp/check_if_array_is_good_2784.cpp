/*

    You are given an integer array nums. We consider an array good
    if it is a permutation of an array base[n].

    base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of
    length n + 1 which contains 1 to n - 1 exactly once, plus two occurrences of n).
    For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].

    Return true if the given array is good, otherwise return false.

    Note: A permutation of integers represents an arrangement of these numbers.


    Example 1:

    Input: nums = [2, 1, 3]
    Output: false
    Explanation: Since the maximum element of the array is 3, the only candidate n
    for which this array could be a permutation of base[n], is n = 3. However, base[3]
    has four elements but array nums has three. Therefore, it can not be a permutation
    of base[3] = [1, 2, 3, 3]. So the answer is false.
    Example 2:

    Input: nums = [1, 3, 3, 2]
    Output: true
    Explanation: Since the maximum element of the array is 3, the only candidate n for
    which this array could be a permutation of base[n], is n = 3. It can be seen that
    nums is a permutation of base[3] = [1, 2, 3, 3] (by swapping the second and fourth
    elements in nums, we reach base[3]). Therefore, the answer is true.
    Example 3:

    Input: nums = [1, 1]
    Output: true
    Explanation: Since the maximum element of the array is 1, the only candidate n for
    which this array could be a permutation of base[n], is n = 1. It can be seen that
    nums is a permutation of base[1] = [1, 1]. Therefore, the answer is true.
    Example 4:

    Input: nums = [3, 4, 4, 1, 2, 1]
    Output: false
    Explanation: Since the maximum element of the array is 4, the only candidate n for
    which this array could be a permutation of base[n], is n = 4. However, base[4] has
    five elements but array nums has six. Therefore, it can not be a permutation of
    base[4] = [1, 2, 3, 4, 4]. So the answer is false.


    Constraints:

    1 <= nums.length <= 100
    1 <= num[i] <= 200

*/

// APPROACH: sort nums in ascending order. Find the maximum
// value of nums and call it m.
// if the length of nums is not equal to m + 1 return false
// Find the base[m] by looping
// from index 0 to m and adding each number into the bas[m] vector
// add m twice into the vector.
// Loop through each value of nums
// comparing it to base[m] return false if there is a difference
// return true otherwise

bool isGood(vector<int>& nums) {
    stable_sort(nums.begin(), nums.end());
    int n = nums.size();
    int m = nums[n - 1];
    vector<int> baseM;

    if (n != m + 1) return false;

    for (int i = 1; i <= m; i++) {
        baseM.push_back(i);
    }

    baseM.push_back(m);

    for (int i = 0; i < n; i++) {
        if (nums[i] != baseM[i]) return false;
    }

    return true;

}



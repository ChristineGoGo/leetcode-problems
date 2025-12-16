/*

    The array-form of an integer num is an array representing its digits in left to right order.

    For example, for num = 1321, the array form is [1,3,2,1].
    Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.


    Example 1:

    Input: num = [1,2,0,0], k = 34
    Output: [1,2,3,4]
    Explanation: 1200 + 34 = 1234
    Example 2:

    Input: num = [2,7,4], k = 181
    Output: [4,5,5]
    Explanation: 274 + 181 = 455
    Example 3:

    Input: num = [2,1,5], k = 806
    Output: [1,0,2,1]
    Explanation: 215 + 806 = 1021

    Constraints:

    1 <= num.length <= 104
    0 <= num[i] <= 9
    num does not contain any leading zeros except for the zero itself.
    1 <= k <= 104

*/


#include <iostream>
using namespace std;

// APPROACH: Use basic addition ie [1, 2, 3] + 99
// is 99 + 3 = 102, keep the 2 in a new vector
// 102 / 10 = 10. Add the next 10 + 2 = 12 keep the 2(12 % 10)
// carry the 1 and it becomes 1 + 1
// return the reverse of the result vector
vector<int> addToArrayForm(vector<int>& num, int k) {
    int n = num.size();
    vector<int> res;
    int idx = n - 1;

    while (k > 0 || idx >= 0) {
        if (idx >= 0) {
            k += num[idx];
        }
        res.push_back(k % 10);

        k /= 10;
        idx--;
    }

    reverse(res.begin(), res.end());

    return res;
}




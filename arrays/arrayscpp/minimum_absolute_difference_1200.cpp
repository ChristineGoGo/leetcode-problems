/*

    Given an array of distinct integers arr, find all pairs of 
    elements with the minimum absolute difference of any two elements.

    Return a list of pairs in ascending order(with respect to pairs),
    each pair [a, b] follows

        a, b are from arr
        a < b
        b - a equals to the minimum absolute difference of any two elements in arr
    

    Example 1:

    Input: arr = [4,2,1,3]
    Output: [[1,2],[2,3],[3,4]]
    Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
    Example 2:

    Input: arr = [1,3,6,10,15]
    Output: [[1,3]]
    Example 3:

    Input: arr = [3,8,-10,23,19,-4,-14,27]
    Output: [[-14,-10],[19,23],[23,27]]
    

    Constraints:

    2 <= arr.length <= 105
    -106 <= arr[i] <= 106
*/
#include <iostream>
#include <vector>

using namespace std;

// APPROACH: Sort the array. Loop through array to find
//  the absolute difference.  Loop and store the 2 values with 
// difference equal to the absolute difference
// in the results array and return the array
vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> result;
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        

        // find the minimum absolute difference
        for (int i = 1; i < n; i++) {
            int curr = arr[i] - arr[i -1];

            if (curr < diff) {
                diff = curr;
            }
        }
        cout << diff;
        //  add the arrays that add up to the difference

        for (int i = 1; i < n; i++) {
            int curr = arr[i] - arr[i - 1];
            vector<int> ans;

            if (curr == diff) {
                ans.push_back(arr[i - 1]);
                ans.push_back(arr[i]);

                result.push_back({arr[i - 1], arr[i]});
            }

        }
        return result;

}

int main() {
    vector<int> s = {40, 11, 26, 27, -20};
    vector<vector<int>> res = minimumAbsDifference(s);
    int n = res.size();

    for (int i = 0; i < n; i++) {
        for (int num: res[i]) {
            cout << num;
        }
    }
    return 0;
}
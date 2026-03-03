/*
    Given a m x n binary matrix mat, find the 0-indexed position of the row that
    contains the maximum count of ones, and the number of ones in that row.

    In case there are multiple rows that have the maximum count of ones,
    the row with the smallest row number should be selected.

    Return an array containing the index of the row, and the number of ones in it.


    Example 1:

    Input: mat = [[0,1],[1,0]]
    Output: [0,1]
    Explanation: Both rows have the same number of 1's.
    So we return the index of the smaller row, 0, and the maximum
    count of ones (1). So, the answer is [0,1].
    Example 2:

    Input: mat = [[0,0,0],[0,1,1]]
    Output: [1,2]
    Explanation: The row indexed 1 has the maximum count of ones (2).
    So we return its index, 1, and the count. So, the answer is [1,2].

    Example 3:
    Input: mat = [[0,0],[1,1],[0,0]]
    Output: [1,2]
    Explanation: The row indexed 1 has the maximum count of ones (2).
    So the answer is [1,2].


    Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 100
    mat[i][j] is either 0 or 1.

*/

// APPROACH: Create results vector,a variable to store the count of maximum 1s
// Create a map to store the row index along with
// its total number of 1's. Loop and find the maximum 1s
// Loop and find the row with the maximum 1s
vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    vector<int> res; int mCount = 0; int n = mat.size();
    map<int, int> freq;

    for(int i = 0; i < n;i++) {
        int cCount = 0;
        for(int j = 0; j < mat[i].size(); j++){
            if(mat[i][j] == 1) cCount++;
        }
        freq[i] = cCount;
    }
    for(auto vals: freq) {
        if (vals.second > mCount) mCount = vals.second;
    }
    for (int i = 0; i < n;i++) {
        if (freq[i] == mCount) {
            res.push_back(i);
            res.push_back(mCount);
            break;
        }
    }

    return res;

}






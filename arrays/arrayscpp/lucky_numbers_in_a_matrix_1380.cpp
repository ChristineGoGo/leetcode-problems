/*
    Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

    A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.



    Example 1:
    Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
    Output: [15]
    Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.

    Example 2:
    Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
    Output: [12]
    Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.

    Example 3:
    Input: matrix = [[7,8],[1,2]]
    Output: [7]
    Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.


    Constraints:
    m == mat.length
    n == mat[i].length
    1 <= n, m <= 50
    1 <= matrix[i][j] <= 105.
    All elements in the matrix are distinct.
*/

// APPROACH: Create vector to store the results
// Populate the columns in a vector
// Insert all the minimum elements in row into a vector
// Insert all the max elements in  pop cols into a vector
// Loop through populated max and min elements adding to the result
// return the result

vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    vector<int> res;
    vector<vector<int>> cols;
    vector<int> minRows;
    vector<int> maxCols;

    int n = matrix.size();
    int m = matrix[0].size();

    // populate columns
    for (int i = 0; i < m; i++ ) {
        vector<int> currCol;
        for (int j = 0; j < n; j++) {
                currCol.push_back(matrix[j][i]);
        }
        cols.push_back(currCol);
    }


    // find the min rows
    for (int i = 0; i < n; i++) {
        int mRow = 100000;
        for (int j = 0; j < matrix[i].size(); j++) {
            mRow = min(mRow, matrix[i][j]);
        }
        minRows.push_back(mRow);
    }

    // find the max cols
    for (int i = 0; i < cols.size(); i++) {
        int mCol = 1;
        for (int j = 0; j < cols[i].size(); j++) {
            mCol = max(mCol, cols[i][j]);
        }
        maxCols.push_back(mCol);
    }

    // find the min rows and max cols equivalents
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == minRows[i] && matrix[i][j] == maxCols[j]) {
                res.push_back(matrix[i][j]);
            }
        }
    }

    return res;

}


/*
    Given a 2D integer array matrix, return the transpose of matrix.

    The transpose of a matrix is the matrix flipped over its main
    diagonal, switching the matrix's row and column indices.

    Example 1:
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [[1,4,7],[2,5,8],[3,6,9]]

    Example 2:
    Input: matrix = [[1,2,3],[4,5,6]]
    Output: [[1,4],[2,5],[3,6]]

    Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 1000
    1 <= m * n <= 10**5
    -109 <= matrix[i][j] <= 10** 9

*/




// APPROACH: Create a vector to store the result
// Create variable n to store the total columns
// Create variable m to store the total rows
// Loop for each index first populating each row then the columns
//      - add each row to the result vector
// return the result vector

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    vector<vector<int>> res;
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < n; i++) {
        vector<int> rows;
        for (int j = 0; j < m; j++) {
            rows.push_back(matrix[j][i]);

        }
        res.push_back(rows);
    }

    return res;
}


/*

    In MATLAB, there is a handy function called reshape which can reshape an m x n
    matrix into a new one with a different size r x c keeping its original data.

    You are given an m x n matrix mat and two integers r and c representing the number
    of rows and the number of columns of the wanted reshaped matrix.

    The reshaped matrix should be filled with all the elements of the original matrix
    in the same row-traversing order as they were.

    If the reshape operation with given parameters is possible and legal, output the new
    reshaped matrix; Otherwise, output the original matrix.

    Example 1:
        Input: mat = [[1,2],[3,4]], r = 1, c = 4
        Output: [[1,2,3,4]]

    Example 2:

    Input: mat = [[1,2],[3,4]], r = 2, c = 4
    Output: [[1,2],[3,4]]


    Constraints:

        m == mat.length
        n == mat[i].length
        1 <= m, n <= 100
        -1000 <= mat[i][j] <= 1000
        1 <= r, c <= 300

*/

// APPROACH: Create a vector of vectors to store the result
// Find total numbers in mat which is n(rows) * m (columns)
// if total numbers are less than or greater than r * c return mat
// Loop for each number in mat:
//      - populate each row in result
//      - fill each row with c columns
// Return result

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

    int totNums = mat[0].size() * mat.size();
    if (totNums != (r * c)) return mat;

    vector<vector<int>> result(r, vector<int>(c));
    int currCol = 0; int currRow = 0;
    for (int i = 0; i < mat.size(); i++) {
        for (int j= 0; j < mat[i].size(); j++) {
            result[currRow][currCol] = mat[i][j];
            currCol++;

            if (currCol == c) {
                currCol = 0;
                currRow++;
            }
        }

    }


    return result;
}


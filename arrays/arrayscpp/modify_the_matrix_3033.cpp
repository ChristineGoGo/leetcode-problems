/*

        Given a 0-indexed m x n integer matrix matrix, create a new 0-indexed matrix called answer.
        Make answer equal to matrix, then replace each element with the value -1 with the maximum
        element in its respective column.

        Return the matrix answer.


        Example 1:
            Input: matrix = [[1,2,-1],[4,-1,6],[7,8,9]]
            Output: [[1,2,9],[4,8,6],[7,8,9]]
            Explanation: The diagram above shows the elements that are changed (in blue).
            - We replace the value in the cell [1][1] with the maximum value in the column 1, that is 8.
            - We replace the value in the cell [0][2] with the maximum value in the column 2, that is 9.

        Example 2:
            Input: matrix = [[3,-1],[5,2]]
            Output: [[3,2],[5,2]]
            Explanation: The diagram above shows the elements that are changed (in blue).


        Constraints:

            m == matrix.length
            n == matrix[i].length
            2 <= m, n <= 50
            -1 <= matrix[i][j] <= 100
            The input is generated such that each column contains at least one non-negative integer.
*/


// APPROACH: Create a new matrix called answer
// Create a map to store each column and maximum val of column
// Loop for each column in matrix finding max val and adding to map
// Loop for each item in matrix:
//      - if item not equal to -1, add to answer
//      - if item is -1 add equivalent max column value to answer
// Return answer
vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(); int n = matrix[0].size();
    vector<vector<int>> answer(m, vector<int>(n,0));
    map<int, int> colMappings; int maxCol = 0;

    for(int i = 0; i < n;i++) {
        int currMax = 0;
        for (int j = 0; j < m; j++) {

            currMax = matrix[j][i];
            maxCol = max(currMax, maxCol);
        }
        colMappings[i] = maxCol;
        maxCol = 0;
    }

    for (int i = 0; i < m; i++) {
        for(int j = 0; j <n; j++) {

            if (matrix[i][j] == -1) {
                matrix[i][j] = colMappings[j];
            }
            answer[i][j] = matrix[i][j];

        }
    }

    return matrix;
}



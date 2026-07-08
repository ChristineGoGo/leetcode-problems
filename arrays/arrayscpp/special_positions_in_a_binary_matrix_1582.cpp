/*
    Given an m x n binary matrix mat, return the number of special positions in mat.

        A position (i, j) is called special if mat[i][j] == 1 and all other elements in
        row i and column j are 0 (rows and columns are 0-indexed).


    Example 1:
        Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
        Output: 1
        Explanation: (1, 2) is a special position because mat[1][2] == 1 and
        all other elements in row 1 and column 2 are 0.

    Example 2:
        Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
        Output: 3
        Explanation: (0, 0), (1, 1) and (2, 2) are special positions.

    Constraints:

        m == mat.length
        n == mat[i].length
        1 <= m, n <= 100
        mat[i][j] is either 0 or 1.

*/
#include <iostream>
#include <vector>
using namespace std;


// APPROACH: Create variable to store the number of special positions
// Create function to loop through the row given
// Create function to loop throught the column given
// Loop for each item in mat:
//      - if it is 1, loop for each row and column
//      - add to positions if row and column are true
// Return the positions

// Examine the rows
int loopRow(vector<vector<int>> mat, int cr, int j) {
    int m = mat[0].size();

    for (int c = 0; c < m; c++) {
        if (c != j && mat[cr][c] == 1) { return false; }
    }
    return true;

}

// Examine the columns
int loopCol(vector<vector<int>> mat, int cc, int i) {
    int n = mat.size();

    for (int r = 0; r < n; r++) {
        if (r != i && mat[r][c] == 1) { return false; }
    }
    return true;
}

int numSpecial(vector<vector<int>>& mat) {
    int positions = 0;
    int n = mat.size(); int m = mat[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                int row = i; int col = j;
                if (loopRow(mat, row, col) && loopCol(mat, row, col)) positions++;
            }
        }
    }

    return positions;

}






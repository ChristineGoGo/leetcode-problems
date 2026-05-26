/*
    You are given a 2D matrix grid of size m x n. You need to check if each cell grid[i][j] is:

        - Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if it exists).
        - Different from the cell to its right, i.e. grid[i][j] != grid[i][j + 1] (if it exists).

        Return true if all the cells satisfy these conditions, otherwise, return false.

    Example 1:

        Input: grid = [[1,0,2],[1,0,2]]

        All the cells in the grid satisfy the conditions.

    Example 2:

        Input: grid = [[1,1,1],[0,0,0]]

        Output: false

        All cells in the first row are equal.

    Example 3:

        Input: grid = [[1],[2],[3]]

        Output: false




    Cells in the first column have different values.


    Constraints:

        1 <= n, m <= 10
        0 <= grid[i][j] <= 9
*/

// APPROACH: Loop for each row in the grid and each column
// return false if the conditions are not met. Otherwise
// return true
bool satisfiesConditions(vector<vector<int>>& grid) {
    int rows = grid.size() - 1; int cols = grid[0].size() - 1;

    // check the rows
    for (int c = 0; c <= cols; c++) {
        for (int r = 0; r < rows; r++) {
            if(r < rows) {
                if(grid[r][c] != grid[r + 1][c]) return false;
            }
        }
    }

    // check the columns
    for (int r = 0; r <= rows; r++) {
        for (int c = 0; c < cols; c++) {
            if(c < cols) {
                if(grid[r][c] == grid[r][c+1]) return false;
            }
        }
    }



    return true;

}



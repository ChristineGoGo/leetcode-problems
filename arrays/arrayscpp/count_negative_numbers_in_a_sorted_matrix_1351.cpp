/*

    Given a m x n matrix grid which is sorted in non-increasing order both row-wise
    and column-wise, return the number of negative numbers in grid.


    Example 1:

    Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
    Output: 8
    Explanation: There are 8 negatives number in the matrix.

    Example 2:

    Input: grid = [[3,2],[1,0]]
    Output: 0

    Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 100
    -100 <= grid[i][j] <= 10
*/
// APPROACH: Create variable called tot to store the total
// negative numbers in the grid. Loop through each number in
// the grid adding to tot every time a negative number is encountered
int countNegatives(vector<vector<int>>& grid) {
    int tot = 0; int n = grid.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] < 0) tot++;
        }
    }

    return tot++;

}




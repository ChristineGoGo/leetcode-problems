/*

    You are given a n x n 2D array grid containing distinct elements in the range [0, n ** 2 - 1].

    Implement the NeighborSum class:

    NeighborSum(int [][]grid) initializes the object.
    int adjacentSum(int value) returns the sum of elements which are adjacent neighbors of value,
    that is either to the top, left, right, or bottom of value in grid.
    int diagonalSum(int value) returns the sum of elements which are diagonal neighbors of value,
    that is either to the top-left, top-right, bottom-left, or bottom-right of value in grid.

    Example 1:

        Input:

        ["NeighborSum", "adjacentSum", "adjacentSum", "diagonalSum", "diagonalSum"]

        [[[[0, 1, 2], [3, 4, 5], [6, 7, 8]]], [1], [4], [4], [8]]

        Output: [null, 6, 16, 16, 4]

        Explanation:

                 [
                    [0,   1,  2]
                    [3,   4,  5]
                    [6,    7,  8]
                ]



        The adjacent neighbors of 1 are 0, 2, and 4.
        The adjacent neighbors of 4 are 1, 3, 5, and 7.
        The diagonal neighbors of 4 are 0, 2, 6, and 8.
        The diagonal neighbor of 8 is 4.


    Example 2:

        Input:

        ["NeighborSum", "adjacentSum", "diagonalSum"]

        [[[[1, 2, 0, 3], [4, 7, 15, 6], [8, 9, 10, 11], [12, 13, 14, 5]]], [15], [9]]

        Output: [null, 23, 45]

        Explanation:
            [
                [1,   2,  0,   3]
                [4,   7,  15,  6]
                [8,    9,  10,  11]
                [12,   13,  14,  5]

            ]


            The adjacent neighbors of 15 are 0, 10, 7, and 6.
            The diagonal neighbors of 9 are 4, 12, 14, and 15.


        Constraints:

        3 <= n == grid.length == grid[0].length <= 10
        0 <= grid[i][j] <= n2 - 1
        All grid[i][j] are distinct.
        value in adjacentSum and diagonalSum will be in the range [0, n2 - 1].
        At most 2 * n2 calls will be made to adjacentSum and diagonalSum.

*/

class NeighborSum {
    // APPROACH: Initialize the neighbor class to get the
    // vector in adjacentSum and diagonalSum
    // find adjacent values and add them and return the result
    // find diagonal values and add them and return the result
public:
    public:
    vector<vector<int>> g;
    int n;

    NeighborSum(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size();
    }

    int adjacentSum(int value) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(g[i][j] == value){
                    // up
                    int up = i > 0 ? g[i - 1][j] : 0;
                    // down
                    int down = i < n - 1 ? g[i + 1][j]: 0;
                    // right
                    int right = j < n - 1 ? g[i][j + 1] : 0;
                    // left
                    int left = j > 0 ? g[i][j - 1] : 0;

                    return up + down + right + left;
                }

            }
        }
        return -1;
    }

    int diagonalSum(int value) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == value) {
                    int sum = 0;
                    // north west
                    if(i > 0 && j > 0) sum += g[i - 1][j - 1];
                    // north east
                    if(i > 0 && j < n - 1) sum += g[i - 1][j + 1];
                    // south west
                    if(i < n - 1 && j > 0) sum += g[i + 1][j - 1];
                    // south east
                    if(i < n - 1 && j < n - 1) sum += g[i + 1][j + 1];
                    return sum;
                }
            }
        }
        return -1;
    }
};




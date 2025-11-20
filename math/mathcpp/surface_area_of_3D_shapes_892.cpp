/*
    You are given an n x n grid where you have placed 
    some 1 x 1 x 1 cubes. Each value v = grid[i][j] represents 
    a tower of v cubes placed on top of cell (i, j).

    After placing these cubes, you have decided to glue any 
    directly adjacent cubes to each other, forming several irregular 3D shapes.

    Return the total surface area of the resulting shapes.

    Note: The bottom face of each shape counts toward its surface area.

    

    Example 1:


    Input: grid = [[1,2],[3,4]]
    Output: 34
    Example 2:


    Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
    Output: 32
    Example 3:


    Input: grid = [[2,2,2],[2,1,2],[2,2,2]]
    Output: 46
    

    Constraints:

    n == grid.length == grid[i].length
    1 <= n <= 50
    0 <= grid[i][j] <= 50

*/
#include <iostream>
using namespace std;


int surfaceArea(vector<vector<int>>& grid) {
    vector<int> rdirection = {0, 1, 0, -1};
    vector<int> cdirection = {1, 0, -1, 0};

    int n = grid.size();
    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0) {
                res += 2;
                for (int k = 0; k <= 3; k++) {
                    int row = i + rdirection[k];
                    int col = j + cdirection[k];
                    int s = 0;

                    if (0 <= row && row < n && 0 <= col && col < n) s = grid[row][col];
                    res += max(grid[i][j] - s, 0);
                }
            }
        }
        
    }
    return res;
}


/*

    There is an m x n matrix that is initialized to all 0's. There is also a 2D array indices where each indices[i] = [ri, ci] represents a 0-indexed location to perform some increment operations on the matrix.

    For each location indices[i], do both of the following:

        1.Increment all the cells on row ri.
        2.Increment all the cells on column ci.
    Given m, n, and indices, return the number of odd-valued cells in the matrix after applying the increment to all locations in indices.

 

    Example 1
        Input: m = 2, n = 3, indices = [[0,1],[1,1]]
        Output: 6
        Explanation: Initial matrix = [[0,0,0],[0,0,0]].
        After applying first increment it becomes [[1,2,1],[0,1,0]].
        The final matrix is [[1,3,1],[1,3,1]], which contains 6 odd numbers.
    
    
    Example 2:
        Input: m = 2, n = 2, indices = [[1,1],[0,0]]
        Output: 0
        Explanation: Final matrix = [[2,2],[2,2]]. There are no odd numbers in the final matrix.
*/


// APPROACH: Create variable to store the result.
// Populate matrix with m * n rows and columns
// Loop through indices adding to the rows and columns as needed
// Return the total odd valued cells
int oddCells(int m, int n, vector<vector<int>>& indices) {
    vector<vector<int>> matrix(m);
    int totOdds = 0;

    // populate matrix
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            matrix[r].push_back(0);
        }
    }


    // perform additions needed
    for (vector idx: indices) {
        int cr = idx[0], cc = idx[1];
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (r == cr) {
                    matrix[r][c]++;
                    
                    
                }
                if (c == cc ) {
                    matrix[r][c]++;
                }
                
            }
        }
    }
    
    // Test
    // for (vector num: matrix) {
    //     for (int i = 0; i < num.size(); i++) {
    //         cout << num[i] << " ";
    //     }
    //     cout << "--------------";
    // }

    // count the total odd values
    for(int r = 0; r < m; r++) {
        for(int c = 0; c < n; c++) {
            if (matrix[r][c] % 2 != 0) totOdds++;
        }
    }

    return totOdds;

}
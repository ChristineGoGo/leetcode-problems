/**
 * You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
 * Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there
 * is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes", meaning the water inside
 * isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width
 * and height don't exceed 100. Determine the perimeter of the island.
 * @param {number[][]} grid
 * @return {number}
 */
 var islandPerimeter = function(grid) {
    let total_sum = 0;
    let current_sum = 0;
    let [up, down, left, right] = [0, 0, 0, 0];
    console.log(grid.length);

    for (let row = 0; row < grid.length; row++) {
        for (let column = 0; column < grid[row].length; column++) {
            if (grid[row][column] === 1) {
                // console.log(`We found an island!  row: ${row}, column: ${column}`);
                // up
                if (row === 0 ) {
                    up = 0;
                } else {
                    up = grid[row - 1][column]
                }
                // down
                if (row === grid.length - 1) {
                    down = 0;
                } else {
                    down = grid[row + 1][column]
                }
                // left
                if (column === 0 ) {
                    left = 0;
                } else {
                    left = grid[row][column - 1]
                }
                // right
                if (column === grid[row].length - 1 ) {
                    right = 0;
                } else {
                    right = grid[row][column + 1]
                }
                current_sum = 4 - (up + down + left + right);
                total_sum += current_sum;
                // console.log(total_sum);
                // console.log(current_sum);
            }

        }
    }
    return total_sum;
};
// test1
let grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]];
// let test1 = islandPerimeter(grid);
// console.log(test1);

// test2
let grid2 = [[1]];
let test2 = islandPerimeter(grid2);
console.log(test2);

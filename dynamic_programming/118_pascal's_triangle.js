/**
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 * 
 * |----------------------|
 * | 1                    |
 * | 1 1                  |
 * | 1 2 1                |
 * | 1 3 3 1              |
 * | 1 4 6 4 1            |
 * |______________________|
 * @param {number} numRows
 * @return {number[][]}
 */


 var generate = function(numRows) {
    // Dynamic programming is used for this
    // First create the triangle
    let triangle = new Array();

    // hande the base case, first array is always 1
    triangle.push([1]);

    // Perform the recurrence relation to solve the overlapping sub problems
    for (let numRow = 1;  numRow < numRows; numRow++) {
        let curr_row = [];
        let prev_row = triangle[numRow - 1];

        // first number is always 1
        curr_row.push(1);

        for (let numCol = 1; numCol < prev_row.length; numCol++) {
            curr_row.push(prev_row[numCol] + prev_row[numCol - 1]);
        }
        // last number is always 1
        curr_row.push(1);

        triangle.push(curr_row)
    }

    return triangle;
};

console.log(generate(5));

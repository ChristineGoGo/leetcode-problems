/*
    Given an integer rowIndex, return the rowIndexth 
    (0-indexed) row of the Pascal's triangle.

    In Pascal's triangle, each number is the sum of the
    two numbers directly above it as shown:


    

    Example 1:

    Input: rowIndex = 3
    Output: [1,3,3,1]
    Example 2:

    Input: rowIndex = 0
    Output: [1]
    Example 3:

    Input: rowIndex = 1
    Output: [1,1]
    

    Constraints:

    0 <= rowIndex <= 33
    

    Follow up: Could you optimize your algorithm 
    to use only O(rowIndex) extra space?
*/
#include <iostream>
#include <map>

using namespace std;
// APPROACH: Use a hashmap to keep track of the rows from 0 to rowIndex
// return the rowIndex array
vector<int> getRow(int rowIndex) {
    map<int, vector<int>> rows;
    rows[0] = {1};
    rows[1] = {1, 1};

    for (int i = 2; i <= rowIndex; i++) {
        int curr = 0;

        while (curr <= i ) {
            if(curr == 0 || curr == i){
                rows[i].push_back(1);
            } else {
                int currSum = 0;
                currSum = rows[i - 1][curr - 1] + rows[i - 1][curr];
                rows[i].push_back(currSum);

            }
            curr++;
        }
    }

    return rows[rowIndex];
}

// APPROACH: dynamic programming







/*
    You are given an array of distinct integers arr and an array of integer arrays pieces,
    where the integers in pieces are distinct. Your goal is to form arr by concatenating
    the arrays in pieces in any order. However, you are not allowed to reorder the integers
    in each array pieces[i].

    Return true if it is possible to form the array arr from pieces. Otherwise, return false.


    Example 1:

        Input: arr = [15,88], pieces = [[88],[15]]
        Output: true
        Explanation: Concatenate [15] then [88]

    Example 2:

        Input: arr = [49,18,16], pieces = [[16,18,49]]
        Output: false
        Explanation: Even though the numbers match, we cannot reorder pieces[0].

    Example 3:
        Input: arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
        Output: true
        Explanation: Concatenate [91] then [4,64] then [78]


    Constraints:

        - 1 <= pieces.length <= arr.length <= 100
        - sum(pieces[i].length) == arr.length
        - 1 <= pieces[i].length <= arr.length
        - 1 <= arr[i], pieces[i][j] <= 100
        - The integers in arr are distinct.
        - The integers in pieces are distinct (i.e., If we flatten pieces in a 1D array,
           all the integers in this array are distinct)
*/


// APPROACH: Create vector to store concatinated pieces values(concatVals)
// Create a map to store the elements of pieces(piecesMappings)
// Loop through each array in pieces, add first element as key
// the rest of the elements in an array
// Loop through each item in array:
//      - if key is found in piecesMappings
//          - add values of the vector in concatVals
// compare each value in  arr to the concatinated vector
//      - if different, return false
// Return true

bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    vector<int> concatVals;
    map<int, vector<int>> piecesMappings;
    int n = pieces.size();

    for (int i = 0; i< n; i++) {
        vector<int> curr;
        for (int j = 0; j < pieces[i].size(); j++) {
            curr.push_back(pieces[i][j]);
        }
        piecesMappings[pieces[i][0]] = curr;
    }

    n = arr.size();

    for (int i = 0; i < n;i++) {
        if (piecesMappings[arr[i]].size() > 0) {
            for(int num: piecesMappings[arr[i]]) {
                concatVals.push_back(num);
            }
        }
    }

    return arr == concatVals;

}


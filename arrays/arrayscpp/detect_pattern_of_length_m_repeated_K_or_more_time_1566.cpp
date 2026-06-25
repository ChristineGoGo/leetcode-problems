/*

    Given an array of positive integers arr, find a pattern of length m that is repeated k or more times.

    A pattern is a subarray (consecutive sub-sequence) that consists of one or more values,
    repeated multiple times consecutively without overlapping. A pattern is defined by its length and the number of repetitions.

    Return true if there exists a pattern of length m that is repeated k or more times, otherwise return false.



    Example 1:

        Input: arr = [1,2,4,4,4,4], m = 1, k = 3
        Output: true
        Explanation: The pattern (4) of length 1 is repeated 4 consecutive times. Notice that pattern can
        be repeated k or more times but not less.

    Example 2:

        Input: arr = [1,2,1,2,1,1,1,3], m = 2, k = 2
        Output: true
        Explanation: The pattern (1,2) of length 2 is repeated 2 consecutive times. Another valid pattern (2,1)
        is also repeated 2 times.

    Example 3:

        Input: arr = [1,2,1,2,1,3], m = 2, k = 3
        Output: false
        Explanation: The pattern (1,2) is of length 2 but is repeated only 2 times.
        There is no pattern of length 2 that is repeated 3 or more times.


    Constraints:

    2 <= arr.length <= 100
    1 <= arr[i] <= 100
    1 <= m <= 100
    2 <= k <= 100
*/

// APPROACH: Create variables pValCount = 0 to track
// the pattern value count and totPatterns = k to track the
// repetition of the patterns
// Loop for each index(i) in arr
// compare arr[i] to arr[i - m] only if i >= m
//  - if the numbers are equal, add pValCount plus one
//    we have another number of the pattern
//  - else, set pValCount = 0 and totPatterns to k(reset numbers)
//  - if pValCount is equal to m, we have a complete pattern
//    reduce patterns by 1
//  - if number of patterns is equal to 1
//     return true since there exists a pattern of length m
//     that is repeated k or more times
// Return false automatically

bool containsPattern(vector<int>& arr, int m, int k) {
    int  n = arr.size();
    int totPatterns = k; int pValCount = 0;

    for (int i = 0; i < n; i++) {
        if (i < m) continue;
        if (arr[i] == arr[i - m]){
            pValCount++;
        } else {
            totPatterns = k;
            pValCount = 0;
        }

        if (pValCount == m) {
            totPatterns--;
            pValCount = 0;
        }

        if (totPatterns == 1) return true;
    }

    return false;

}



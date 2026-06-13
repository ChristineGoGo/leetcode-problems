/*
    Given an array of integers arr, return true if we can partition the array
    into three non-empty parts with equal sums.

    Formally, we can partition the array if we can find indexes i + 1 < j with
    (arr[0] + arr[1] + ... + arr[i] == arr[i + 1] + arr[i + 2] + ... + arr[j - 1]
     == arr[j] + arr[j + 1] + ... + arr[arr.length - 1])


    Example 1:
        Input: arr = [0,2,1,-6,6,-7,9,1,2,0,1]
        Output: true
        Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1

    Example 2:

        Input: arr = [0,2,1,-6,6,7,9,-1,2,0,1]
        Output: false

    Example 3:

        Input: arr = [3,3,6,5,-2,2,5,1,-9,4]
        Output: true
        Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4


    Constraints:

        3 <= arr.length <= 5 * 10**4
        -104 <= arr[i] <= 10**4

*/


// APPROACH: Create variable to store the sum to find
// in order for the array to be divisible by three
// Find the total sum of the numbers in arr
// Return false if the sum isn't divisible by 3
// Create counter to store the number of parts found
// Create temp to store the current running sum
// Create needed to find what the sum of each part is supposed
// to be.
// Loop for each index in arr:
//      - if three parts are found(counter is 3) return true;
//      - add current number to temp
//          - if temp is equal to needed sum return true
//          - set temp to equal 0
//          - add to counter to track the parts
// return false
bool canThreePartsEqualSum(vector<int>& arr) {
    int sum1 = 0; int n = arr.size();
    for (int i = 0; i < n; i++) {
        sum1 += arr[i];
    }
    if (sum1 % 3 != 0) return false;
    int temp = 0; int needed = sum1/3; int counter = 1;

    for(int i = 0; i < n; i++) {
        if (counter == 3) return true;
        temp += arr[i];
        if (temp == needed){
            counter++;
            temp = 0;
            continue;
        }

    }

    return false;

}




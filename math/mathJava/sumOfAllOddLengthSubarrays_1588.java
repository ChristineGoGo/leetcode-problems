/*
    Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.

    A subarray is a contiguous subsequence of the array.

    

    Example 1:

    Input: arr = [1,4,2,5,3]
    Output: 58
    Explanation: The odd-length subarrays of arr and their sums are:
    [1] = 1
    [4] = 4
    [2] = 2
    [5] = 5
    [3] = 3
    [1,4,2] = 7
    [4,2,5] = 11
    [2,5,3] = 10
    [1,4,2,5,3] = 15
    If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
    Example 2:

    Input: arr = [1,2]
    Output: 3
    Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
    Example 3:

    Input: arr = [10,11,12]
    Output: 66
    

    Constraints:

    1 <= arr.length <= 100
    1 <= arr[i] <= 1000
*/
/*
 * APPROACH: Use the two pointer method to track if the subarray
 * is odd lengthed, if so add it to the running sum. After finishing
 * the loop, return the running sum.
 */


public class sumOfAllOddLengthSubarrays_1588 {
    public static int sumOddLengthSubarrays(int[] arr) {
        int i = 0;
        int n = arr.length;
        int runningSum = 0;

        while (i < n) {
            for (int j = n - 1; j >= 0; j--) {
                // determine if the array is odd length
                int length = j - i + 1;
                if (length % 2 != 0) {
                    for (int c = 0; c < j + 1; c++) {
                        runningSum += arr[c];
                    }
                }
            }
            i++;
        }
        return runningSum;
    }

    public static void main(String[] args) {
        int[] test = {1, 4, 2, 5, 3};
        System.out.println(sumOddLengthSubarrays(test));
    }
 
    
}

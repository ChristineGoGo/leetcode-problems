/*
    Given a positive integer n, find the pivot integer x such that:

    The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
    Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

    

    Example 1:

    Input: n = 8
    Output: 6
    Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
    Example 2:

    Input: n = 1
    Output: 1
    Explanation: 1 is the pivot integer since: 1 = 1.
    Example 3:

    Input: n = 4
    Output: -1
    Explanation: It can be proved that no such integer exist.
    

    Constraints:

    1 <= n <= 1000
*/

/*
 * APPROACH: Use the right and left pointer to keep track
 * of the sum of the left upto x and the sum of the right,
 * from x upto n. If the sums are equal return the value of the 
 * current integer, else return -1 since there doesn't exist
 * a pivot number.
 */

public class findThePivotInteger_2485 {
    public static int pivotInteger(int n) {
        if (n == 1) {
            return 1;
        }
        int left = 1;
        int right = 1;
        int leftSum = 0;
        int rightSum = 0;

        while (right < n) {
            leftSum += left;
            for(int i = left; i <= n; i++) {
                rightSum += i;
            }
            if (rightSum == leftSum) {
                return left;
            }
            left++;
            right = left;
            rightSum = 0;
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(pivotInteger(8));
    }
    
}

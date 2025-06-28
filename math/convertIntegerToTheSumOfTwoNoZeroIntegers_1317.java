/*
    No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

    Given an integer n, return a list of two integers [a, b] where:

    a and b are No-Zero integers.
    a + b = n
    The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.


    Example 1:

    Input: n = 2
    Output: [1,1]
    Explanation: Let a = 1 and b = 1.
    Both a and b are no-zero integers, and a + b = 2 = n.
    Example 2:

    Input: n = 11
    Output: [2,9]
    Explanation: Let a = 2 and b = 9.
    Both a and b are no-zero integers, and a + b = 11 = n.
    Note that there are other valid answers as [8, 3] that can be accepted.
    

    Constraints:

    2 <= n <= 104
*/

import java.util.Arrays;

public class convertIntegerToTheSumOfTwoNoZeroIntegers_1317 {
    public static int[] getNoZeroIntegers(int n) {
        int left = 1;
        int right = n - 1;

        while (left < right) {
            String currL = Integer.toString(left);
            String currR = Integer.toString(right);

            if (currL.contains("0") || currR.contains("0")) {
                left++;
                right--;
                continue;
            }
            if (left + right == n ) {
                break;
            }

        }
        int[] res = {left, right};
        return res;
    }

    public static void main(String[] args) {
        int[] result = getNoZeroIntegers(11);
        System.out.println(Arrays.toString(result));
    }
    
}

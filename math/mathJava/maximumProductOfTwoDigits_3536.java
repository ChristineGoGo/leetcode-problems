
import java.util.Arrays;

/*
You are given a positive integer n.

Return the maximum product of any two digits in n.

Note: You may use the same digit twice if it appears more than once in n.



Example 1:

Input: n = 31

Output: 3

Explanation:

The digits of n are [3, 1].
The possible products of any two digits are: 3 * 1 = 3.
The maximum product is 3.
Example 2:

Input: n = 22

Output: 4

Explanation:

The digits of n are [2, 2].
The possible products of any two digits are: 2 * 2 = 4.
The maximum product is 4.
Example 3:

Input: n = 124

Output: 8

Explanation:

The digits of n are [1, 2, 4].
The possible products of any two digits are: 1 * 2 = 2, 1 * 4 = 4, 2 * 4 = 8.
The maximum product is 8.


Constraints:

10 <= n <= 109
 */

 /*
  * APPROACH: Add the individual digits into an array. Sort the array in ascending
  * order. Return the multiple of the last two numbers(biggest numbers)
  */


public class maximumProductOfTwoDigits_3536 {
    public static int maxProduct(int n) {
        String nString = String.valueOf(n);
        int length = nString.length();
        int[] result = new int[length];
        int num = n;
        int start = 0;

        while (num > 0) {
            int current = num % 10;
            result[start] = current;
            num /= 10;
            start++;
        }
        Arrays.sort(result);
        return result[length - 1] * result[length - 2];

    }
    public static void main(String[] args) {
        int test1 = 99999999;
        System.out.println(maxProduct(test1));
    }
}

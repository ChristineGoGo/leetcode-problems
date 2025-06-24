/*
    You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.

    

    Example 1:

    Input: n = 10, t = 2

    Output: 10

    Explanation:

    The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

    Example 2:

    Input: n = 15, t = 3

    Output: 16

    Explanation:

    The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.

    

    Constraints:

    1 <= n <= 100
    1 <= t <= 10
*/

/*
 * APPROACH: Loop from 0 to 100 adding one to n, find the digit product
 * and return if divisible by t
 */


public class smallestDivisibleDigitProductI_3345 {
    public static int smallestNumber(int n, int t) {
        int num = n;
        int product = 1;

        while (num < 100) {
            int currNum = num;
            while (currNum > 0) {
                int current = currNum % 10;
                product *= current;
                currNum /= 10;
            }

            if (product == 0 || (product % t == 0)) {
                return num;
            }
            product = 1;
            num++;
        }
        return num;
    }
    public static void main(String[] args) {
        System.out.println(smallestNumber(15, 3));
    }
    
}

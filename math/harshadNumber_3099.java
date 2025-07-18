/*
    An integer divisible by the sum of its digits is said to be a Harshad number.
    You are given an integer x. Return the sum of the digits of x if x is a Harshad number,
    otherwise, return -1.

    

    Example 1:

    Input: x = 18

    Output: 9

    Explanation:

    The sum of digits of x is 9. 18 is divisible by 9. So 18 is a Harshad number and the answer is 9.

    Example 2:

    Input: x = 23

    Output: -1

    Explanation:

    The sum of digits of x is 5. 23 is not divisible by 5. So 23 is not a Harshad number and the answer is -1.

    

    Constraints:

    1 <= x <= 100
*/

/*
 * APPROACH: Find the sum of the given number's digit if the
 * sum is divisible by the number return the sum otherwise return
 * the number.
 */
public class harshadNumber_3099 {
    public static int sumOfTheDigitsOfHarshadNumber(int x) {
        int total = 0;
        int num = x;

        while( num > 0) {
            int current = num % 10;
            total += current;
            num /= 10;
        }
        // System.out.println("total: " + total);
        return x % total == 0 ? total : -1;
    }

    public static void main(String[] args) {
        System.out.println(sumOfTheDigitsOfHarshadNumber(18));

    }
    
}

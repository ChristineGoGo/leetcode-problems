/**
 * A perfect number is a positive integer that is equal to the sum of its positive divisors, 
 * excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.
 * Given an integer n, return true if n is a perfect number, otherwise return false.
 * Example 1:
 * Input: num = 28
 * Output: true
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 * 1, 2, 4, 7, and 14 are all divisors of 28.
 * Example 2:
 * Input: num = 7
 * Output: false
 * Constraints:
 * 1 <= num <= 108
 */

 /*
  * APPROACH: loop from 1 to num / 2 adding to the running total
  * all the numbers that are divisors of num
  * compare the running total and return the result if they are equal
  */
public class perfectNumber_507 {
        public boolean checkPerfectNumber(int num) {
        int half = num / 2;
        int current = 1;
        int total = 0;

        while (current <= half) {
            if (num % current == 0) {
                // System.out.println(total);
                total += current;
            }
            current++;
        }
        // System.out.println(total);
        return total == num;
    }
}

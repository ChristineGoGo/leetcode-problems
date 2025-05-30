/**
 * You are given a positive integer n. Each digit of n has a sign according to the following rules:
 * the most significant digit is assigned a positive sign.
 * Each other digit has an opposite sign to its adjacent digits.
 * Return the sum of all digits with their corresponding sign.
 *  Example 1:
 *  Input: n = 521
 *  Output: 4
 *  Explanation: (+5) + (-2) + (+1) = 4.
 *  Example 2:
 *  Input: n = 111
 *  Output: 1
 *  Explanation: (+1) + (-1) + (+1) = 1.
 *  Example 3:
 *  Input: n = 886996
 *  Output: 0
 *  Explanation: (+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0.
 * 
 */


 /*
  * APPROACH: Add all the numbers in the odd position of the given digit
  * while subtracting the numbers in the even position.
  */

  public class alternatingDigitSum_2544 {
    public static int alternatingDigitSum(int n) {
        int total = 0;
        int num = n;
        int current;
        int position = String.valueOf(num).length() % 2 == 0 ? 2 : 1;

        while (num > 0) {

            current = num % 10;
            if (position % 2 == 0) {
                total -= current;
            } else {
                total += current;
            }
            num /= 10;
            position += 1;
        }
        return total;
    }

    public static void main(String[] args) {
        int result = alternatingDigitSum(10);
        System.out.println(result);
    }
  }
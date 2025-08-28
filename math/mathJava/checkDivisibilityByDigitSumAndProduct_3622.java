/*

        You are given a positive integer n. 
        Determine whether n is divisible by the sum of the following two values:

        The digit sum of n (the sum of its digits).

        The digit product of n (the product of its digits).

        Return true if n is divisible by this sum; otherwise, return false.

        

        Example 1:

        Input: n = 99

        Output: true

        Explanation:

        Since 99 is divisible by the sum (9 + 9 = 18) plus product
        (9 * 9 = 81) of its digits (total 99), the output is true.

        Example 2:

        Input: n = 23

        Output: false

        Explanation:

        Since 23 is not divisible by the sum (2 + 3 = 5) plus product
         (2 * 3 = 6) of its digits (total 11), the output is false.
 */

public class checkDivisibilityByDigitSumAndProduct_3622 {
    public boolean checkDivisibility(int n) {
        // calculate the digit sum
        // calculate the product sum
        // return if the product sum added to the digit
        // sum is a divisor of n

        // if (n == 1) return false;

        int numProd = n;
        int startProd = 1;

        int numSum = n;
        int startSum = 0;

        while (numProd > 0) {
            // find current val
            int curr = numProd % 10;
            startProd *= curr;
            numProd /= 10;
        }

        while (numSum > 0) {
            // find current val
            int curr = numSum % 10;
            startSum += curr;
            numSum /= 10;
        }
        
        return (n % (startProd + startSum)) == 0;
        
    }

    public static void main(String[] args) {
        System.out.println(1);
        System.out.println( 1 % 2);
    }
    
}

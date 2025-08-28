
/**
 * Given two positive integers a and b, return the number of common factors of a and b.
 * An integer x is a common factor of a and b if x divides both a and b.
 *  Example 1:
 *      Input: a = 12, b = 6
 *      Output: 4
 *      Explanation: The common factors of 12 and 6 are 1, 2, 3, 6.
 * Example 2:
 *      Input: a = 25, b = 30
 *      Output: 2
 *      Explanation: The common factors of 25 and 30 are 1, 5.
 * Constraints:
 * 1 <= a, b <= 1000
 * APPROCH: use a variable to track the common factors and loop from
 * 1 to the smallest given number, if a numbers is a divisor of both
 * given numbers and it to the variable 
*/
public class numberOfCommonFactors_2427 {
    public static int commonFactors(int a, int b) {
        int lowest = a >= b ? b : a;
        int factors = 0;
        int currentFactor = 1;

        while (currentFactor <= lowest) {
            if (a % currentFactor == 0 && b % currentFactor == 0) {
                factors++;
            }
            currentFactor++;
        }
        return factors;
    }

    public static void main(String[] args) {
        System.out.println(commonFactors(12, 6));
    }
    
}

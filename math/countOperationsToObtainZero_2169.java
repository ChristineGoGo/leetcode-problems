/*
 *
 * You are given two non-negative integers num1 and num2.
 * In one operation, if num1 >= num2, you must subtract num2 from num1, otherwise subtract num1 from num2.
 * For example, if num1 = 5 and num2 = 4, subtract num2 from num1, thus obtaining num1 = 1 and num2 = 4. However, if num1 = 4 and num2 = 5, after one operation, num1 = 4 and num2 = 1.
 * Return the number of operations required to make either num1 = 0 or num2 = 0.
 * Example 1:
 * Input: num1 = 2, num2 = 3
 * Output: 3
 * Explanation: - Operation 1: num1 = 2, num2 = 3. Since num1 < num2, 
 * we subtract num1 from num2 and get num1 = 2, num2 = 3 - 2 = 1.- Operation 2: num1 = 2, num2 = 1. Since num1 > num2, 
 * we subtract num2 from num1.- Operation 3: num1 = 1, num2 = 1. Since num1 == num2, we subtract num2 from num1.
 * Now num1 = 0 and num2 = 1. Since num1 == 0, we do not need to perform any further operations.
 * So the total number of operations required is 3.
 * Example 2:
 * Input: num1 = 10, num2 = 10
 * Output: 1
 * Explanation: 
 * - Operation 1: num1 = 10, num2 = 10. Since num1 == num2, we subtract num2 
 * from num1 and get num1 = 10 - 10 = 0.Now num1 = 0 and num2 = 10. Since num1 == 0, we are 
 * done.So the total number of operations required is 1.
 * Constraints:
 * 0 <= num1, num2 <= 105 
 */

/*
 * APPROACH: use a temporary variable to track the difference between num1 and num2
 * and another variable to track the running number of operations performed. Use
 * a while loop while performing each operation and ensure the loop stops when 
 * either num1 or num2 is zero
 */
public class countOperationsToObtainZero_2169 {
    public static int countOperations(int num1, int num2) {
        int operations = 0;
        int difference;

        while (num1 > 0 && num2 > 0) {
            if (num1 >= num2) {
                difference = num1 - num2;
                num1 = difference;
            } else {
                difference = num2 - num1;
                num2 = difference;
            }
            operations ++;
        }
        return operations;
    }

    public static void main(String[] args) {
        int result = countOperations(10, 10);
        System.out.println(result);
    }
    
}

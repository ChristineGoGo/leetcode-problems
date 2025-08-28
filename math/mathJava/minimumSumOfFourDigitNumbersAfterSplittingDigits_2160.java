
import java.util.Arrays;

/*
 * You are given a positive integer num consisting of exactly four digits. 
 * Split num into two new integers new1 and new2 by using the digits found in num.
 * Leading zeros are allowed in new1 and new2, 
 * and all the digits found in num must be used.For example, 
 * given num = 2932, you have the following digits: two 2's, one 9 and one 3. Some of the possible pairs
 * [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].
 * Return the minimum possible sum of new1 and new2.
 * Example 1:
 * Input: num = 2932
 * Output: 52
 * Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
 * The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.
 * Example 2:
 * Input: num = 4009
 * Output: 13
 * Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], etc. 
 * The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.
 * Constraints:
 * 1000 <= num <= 9999
 */

 /*
  * APPROACH: Insert all the numbers in num into an array. Sort the array 
  * The minimum sum is the sum of sortedArr[0] * 10 + sortedArray[3] and
  * sortedArray[1] * 10 + sortedArray[2]
  */
public class minimumSumOfFourDigitNumbersAfterSplittingDigits_2160 {
    public static int minimumSum(int num) {
        int[] arr = new int[4];
        int n = num;
        int i = 0;

        while (n > 0) {
            int current = n % 10;
            arr[i] = current;
            i++;
            n /= 10;
        }
        
        Arrays.sort(arr);
        int num1 = (arr[0] * 10) + arr[3]; 
        int num2 = (arr[1] * 10) + arr[2];
        
        return num1 + num2;

    }
    public static void main(String[] args) {
        int test1 = 4009;
        System.out.println(minimumSum(test1));
        
    }
}

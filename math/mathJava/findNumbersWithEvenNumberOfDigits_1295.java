/*
Given an array nums of integers, return how many of them contain an even number of digits.

 

Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.
Example 2:

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.
 

Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 105

*/

/*
 * APPROACH: Create a function to count the number of digits
 * of a number. Loop through the array, if the  number of digits is
 * even, add to the total running sum. Return the sum.
 */


public class findNumbersWithEvenNumberOfDigits_1295 {
    public static boolean isEvenDigit(int num) {
        int start = num;
        int current = 0;

        while (start > 0) {
            start /= 10;
            current++;
        }
        boolean result = current % 2 == 0 ? true : false;
        return result;
    } 
    public static int findNumbers(int[] nums) {
        int totalSum =0;
        for (int i = 0; i < nums.length; i++) {
            if (isEvenDigit(nums[i])) {
                totalSum++;
            }
        }
        return totalSum;
    }

    public static void main(String[] args) {
        int[] test1 = {12,345,2,6,7896};
        System.out.println(findNumbers(test1));
    }
    
}

/*
    Given a positive integer num, split it into two non-negative
    integers num1 and num2 such that:

    The concatenation of num1 and num2 is a permutation of num.
    In other words, the sum of the number of occurrences of each
    digit in num1 and num2 is equal to the number of occurrences 
    of that digit in num.
    num1 and num2 can contain leading zeros.
    Return the minimum possible sum of num1 and num2.

    Notes:

    It is guaranteed that num does not contain any leading zeros.
    The order of occurrence of the digits in num1 and num2 may differ
    from the order of occurrence of num.
    

    Example 1:

    Input: num = 4325
    Output: 59
    Explanation: We can split 4325 so that num1 is 24 and num2 is 35,
    giving a sum of 59. We can prove that 59 is indeed the minimal possible sum.
    Example 2:

    Input: num = 687
    Output: 75
    Explanation: We can split 687 so that num1 is 68 and num2 is 7, 
    which would give an optimal sum of 75.
    

    Constraints:

    10 <= num <= 109
*/

import java.util.Arrays;

public class splitWithMinimumSum_2578 {
    public int splitNum(int num) {
        /*
        *APPROACH: Sort the numbers in num
        * in ascending order. Alternately
        * add the first 2 and the last 2 
        * numbers to get the minimum sum 
        */
        String sNum = Integer.toString(num);
        int n = sNum.length();
        int[] arr = new int[n];
        int start = 0;
        int cNum = num;

        while (cNum > 0) {
            int current = cNum % 10;
            arr[start] = current;
            cNum /= 10;
            start++;
        }
        Arrays.sort(arr);
        String num1 = "";
        String num2 = "";

        for (int i = 0; i < n; i++) {
            String cStr = Integer.toString(arr[i]);
            if (i % 2 == 0) {
                num1 += cStr;
            } else {
                num2 += cStr;
            }
        }

        return Integer.parseInt(num1) + Integer.parseInt(num2);
    }
    
}

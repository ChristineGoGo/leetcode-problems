/*

    You are given an integer num. You know that Bob will sneakily
    remap one of the 10 possible digits (0 to 9) to another digit.

    Return the difference between the maximum and minimum values Bob
    can make by remapping exactly one digit in num.

    Notes:

    When Bob remaps a digit d1 to another digit d2, Bob replaces all
    occurrences of d1 in num with d2.
    Bob can remap a digit to itself, in which case num does not change.
    Bob can remap different digits for obtaining minimum and maximum
    values respectively.
    The resulting number after remapping can contain leading zeroes.
    

    Example 1:

    Input: num = 11891
    Output: 99009
    Explanation: 
    To achieve the maximum value, Bob can remap the digit 1 to the digit
    9 to yield 99899.
    To achieve the minimum value, Bob can remap the digit 1 to the digit 0
    , yielding 890.
    The difference between these two numbers is 99009.
    Example 2:

    Input: num = 90
    Output: 99
    Explanation:
    The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
    Thus, we return 99.
    

    Constraints:

    1 <= num <= 108
*/

public class maximumDifferenceByRemappingADigit_2566 {
    public int minMaxDifference(int num) {
        /*
        * APPROACH: Remap first value and its occurences
        *  to 0 to get the minimum value possible
        * Remap first value and its occurences to 9 to
        * get the minimum value possible
         */
        String sNum = Integer.toString(num);
        int first = Integer.parseInt(sNum.charAt(0) + "");
        int start = 0;
         
        String max = "";
        String min = "";

        // get the maximum value 
        for (int i = 0; i < sNum.length(); i++) {
            if (first == 9 ) {
                while (first == 9 && start < sNum.length()) {
                    first = Integer.parseInt(sNum.charAt(start) + "");
                    start++;
                }
            }
            
            String currS = sNum.charAt(i) + "";
            int currN = Integer.parseInt(currS);
            // get the maximum value by remapping to 9
            if (currN == first && currN != 9 ) {
                max += "9";
            } else {
                max += currS;
            }
        }
        // System.out.println("Maximum value is: " + max);

        first = Integer.parseInt(sNum.charAt(0) + "");

        // get the minimum value 
        for (int i = 0; i < sNum.length(); i++) {
            String currS = sNum.charAt(i) + "";
            int currN = Integer.parseInt(currS);
            // get the minimum value by remapping to 0
            if (currN == first && currN != 0 ) {
                min += "0";
            } else {
                min += currS;
            }
        }

        // return the resulting difference
        return Integer.parseInt(max) - Integer.parseInt(min);
    }
    
}

/*

    You are given two positive integers low and high.

    An integer x consisting of 2 * n digits is symmetric 
    if the sum of the first n digits of x is equal to the sum
    of the last n digits of x. Numbers with an odd number of digits
    are never symmetric.

    Return the number of symmetric integers in the range [low, high].

    

    Example 1:

    Input: low = 1, high = 100
    Output: 9
    Explanation: There are 9 symmetric integers between 1 and 100:
    11, 22, 33, 44, 55, 66, 77, 88, and 99.
    Example 2:

    Input: low = 1200, high = 1230
    Output: 4
    Explanation: There are 4 symmetric integers between 1200 and 1230:
    1203, 1212, 1221, and 1230.
    

    Constraints:

    1 <= low <= high <= 104
*/


public class countSymmetricIntegers_2843 {
    //APPROACH: count the # of digits in the numbers
    // of the range low to high continue
    // if the digit count is odd. If the # of digits
    // is even, determine if the integer is symetric
    // by finding if the sum of 0: n/2 digits is 
    // equal to the sum of n/2: end of digit 

    public int countSymmetricIntegers(int low, int high) {
        int start = low;
        int total = 0;

        while (start <= high) {
            String currS = Integer.toString(start);
            int n = currS.length();
            // System.out.println(currS);
            if (n % 2 == 0) {
                String firstS = currS.substring(0, n/2);
                String lastS = currS.substring(n/2, n);

                int fSum = 0;
                int lSum = 0;

                // count the first sum of the o:n/2 digits
                for (int i = 0; i < firstS.length(); i++) {
                    int currInt = Integer.valueOf(firstS.charAt(i) + "");
                    fSum += currInt;
                }

                // count the last sum of the n/2:n digits
                for (int i = 0; i < lastS.length(); i++) {
                    int currInt = Integer.valueOf(lastS.charAt(i) + "");
                    lSum += currInt;
                }
           
                if (lSum == fSum) total++;
            }
            start++;
        }

        return total;
    }
    
}

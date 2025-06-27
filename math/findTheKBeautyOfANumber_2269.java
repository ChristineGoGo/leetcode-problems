/*

    The k-beauty of an integer num is defined as the number of substrings of 
    num when it is read as a string that meet the following conditions:

    It has a length of k.
    It is a divisor of num.
    Given integers num and k, return the k-beauty of num.

    Note:

    Leading zeros are allowed.
    0 is not a divisor of any value.
    A substring is a contiguous sequence of characters in a string.

    

    Example 1:

    Input: num = 240, k = 2
    Output: 2
    Explanation: The following are the substrings of num of length k:
    - "24" from "240": 24 is a divisor of 240.
    - "40" from "240": 40 is a divisor of 240.
    Therefore, the k-beauty is 2.
    Example 2:

    Input: num = 430043, k = 2
    Output: 2
    Explanation: The following are the substrings of num of length k:
    - "43" from "430043": 43 is a divisor of 430043.
    - "30" from "430043": 30 is not a divisor of 430043.
    - "00" from "430043": 0 is not a divisor of 430043.
    - "04" from "430043": 4 is not a divisor of 430043.
    - "43" from "430043": 43 is a divisor of 430043.
    Therefore, the k-beauty is 2.
    

    Constraints:

    1 <= num <= 109
    1 <= k <= num.length (taking num as a string)
*/

/*
 * APPROACH:
 * 1. Use a variable to track the k-beauty
 * 2. Convert the num to a string
 * 3. Loop through the string and add to k-beauty
 * whenever neccessary
 * 4.Return the K-beauty
 */


public class findTheKBeautyOfANumber_2269 {
    public static int divisorSubstrings(int num, int k) {
        String stringNum = Integer.toString(num);
        int kBeauty = 0;
        
        for (int i = 0; i <= stringNum.length() - k; i++) {
            String sub = stringNum.substring(i, i + k);
            int current = Integer.parseInt(sub);
            System.out.println(current);
            
            if (current == 0) {
                continue;
            }
            if (num % current == 0) {
                kBeauty++;
            }
        }
        return kBeauty;
    }
    
    public static void main(String[] args) {
        System.out.println(divisorSubstrings(240, 2));
        // System.out.println(Integer.parseInt("04"));
    }
    
}

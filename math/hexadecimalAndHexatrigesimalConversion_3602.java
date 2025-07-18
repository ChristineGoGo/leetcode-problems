/*
    You are given an integer n.

    Return the concatenation of the hexadecimal representation of
    n2 and the hexatrigesimal representation of n3.

    A hexadecimal number is defined as a base-16 numeral system that
    uses the digits 0 – 9 and the uppercase letters A - F to represent values from 0 to 15.

    A hexatrigesimal number is defined as a base-36 numeral system that uses the digits 0 – 9
    and the uppercase letters A - Z to represent values from 0 to 35.

    

    Example 1:

    Input: n = 13

    Output: "A91P1"

    Explanation:

    n2 = 13 * 13 = 169. In hexadecimal, it converts to (10 * 16) + 9 = 169,
    which corresponds to "A9".
    n3 = 13 * 13 * 13 = 2197. In hexatrigesimal, it converts to (1 * 362)
    + (25 * 36) + 1 = 2197, which corresponds to "1P1".
    Concatenating both results gives "A9" + "1P1" = "A91P1".
    Example 2:

    Input: n = 36

    Output: "5101000"

    Explanation:

    n2 = 36 * 36 = 1296. In hexadecimal, it converts to (5 * 162) + (1 * 16) + 0 = 1296,
    which corresponds to "510".
    n3 = 36 * 36 * 36 = 46656. In hexatrigesimal, it converts to (1 * 363) + (0 * 362) + 
    (0 * 36) + 0 = 46656, which corresponds to "1000".
    Concatenating both results gives "510" + "1000" = "5101000".
    

    Constraints:

    1 <= n <= 1000
 */

 /*
  * APPROACH: Use the Java builtin function to convert to base 16 and base 36
  * after squaring n and finding its cube.(Integer.toString())
  */

public class hexadecimalAndHexatrigesimalConversion_3602 {
    public static String concatHex36(int n) {
        String toBase16 = Integer.toString(n * n, 16);
        String toBase36 = Integer.toString(n * n * n, 36);
        String result = toBase16 + toBase36;
        return result.toUpperCase(); 
    }

    public static void main(String[] args) {
        System.out.println(concatHex36(13));
    }
    
}

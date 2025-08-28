/* 
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

 

Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true
 */
public class powerOfFour_342{
    public boolean isPowerOfFour(int n) {
        int start = 0;
        int end = 20;

        while (start <= end) {
            if (Math.pow(4, start) == n) {
                return true;
            }
            start ++;
        }
        return false;
    }
}
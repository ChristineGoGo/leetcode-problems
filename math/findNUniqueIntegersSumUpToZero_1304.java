
import java.util.Arrays;

/*
Given an integer n, return any array containing n unique integers such that they add up to 0.

 

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]
 

Constraints:

1 <= n <= 1000*/

/*
 * APPROACH: create an array to store the results.
 * Use right and left pointer to populate the array
 */


public class findNUniqueIntegersSumUpToZero_1304 {
    public static int[] sumZero(int n) {
        int right = n - 1;
        int left = 0;
        int start = 1;
        int[] result = new int[n];

        while (left < right) {
            result[right] = start;
            result[left] = start * -1;
            start++;
            right--;
            left++;
        }
        return result;

    }
    public static void main(String[] args) {
        System.out.println(Arrays.toString(sumZero(15)));
    }
    
}

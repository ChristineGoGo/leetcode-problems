/*
    You are given an array of positive integers nums.

    An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:

    prod(arr) is the product of all elements of arr.
    gcd(arr) is the GCD of all elements of arr.
    lcm(arr) is the LCM of all elements of arr.
    Return the length of the longest product equivalent subarray of nums.

    

    Example 1:

    Input: nums = [1,2,1,2,1,1,1]

    Output: 5

    Explanation: 

    The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.

    Example 2:

    Input: nums = [2,3,4,5,6]

    Output: 3

    Explanation: 

    The longest product equivalent subarray is [3, 4, 5].

    Example 3:

    Input: nums = [1,2,3,1,4,5,1]

    Output: 5

    

    Constraints:

    2 <= nums.length <= 100
    1 <= nums[i] <= 10
*/


/*
 * APPROACH: Create function for find the product of all elements of the array,
 * GCD of all elements of an array and the LCM of all elements of the array
 * Use the sliding window method to find all possible combinations of the array
 * and finally the longest array with the requirement
 */


public class maximumSubarrayWithEqualProducts_3411 {
    public static int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    public static int lcm(int a, int b) {
        return (a * b)/ gcd(a, b);
    }

    public int maxLength(int[] nums) {
        int maxLen = 0;
        int n = nums.length;

        for(int i = 0; i < n; i++) {
            int prod = nums[i];
            int l = nums[i];
            int g = nums[i];

            for (int j = i + 1; j < n; j++) {
                prod *= nums[j];
                l = lcm(l, nums[j]);
                g = gcd(g, nums[j]);

                if (prod == (l * g)) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                    }
                } else {
                    break;
                }
            }
        }
        return maxLen;
    }

    public static void main(String[] args) {
        System.out.println(lcm(6, 10));
    }
    
}

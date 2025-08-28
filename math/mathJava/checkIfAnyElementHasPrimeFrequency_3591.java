import java.util.*;
/*
    You are given an integer array nums.

    Return true if the frequency of any element of the array is prime, otherwise, return false.

    The frequency of an element x is the number of times it occurs in the array.

    A prime number is a natural number greater than 1 with only two factors, 1 and itself.

    

    Example 1:

    Input: nums = [1,2,3,4,5,4]

    Output: true

    Explanation:

    4 has a frequency of two, which is a prime number.

    Example 2:

    Input: nums = [1,2,3,4,5]

    Output: false

    Explanation:

    All elements have a frequency of one.

    Example 3:

    Input: nums = [2,2,2,4,4]

    Output: true

    Explanation:

    Both 2 and 4 have a prime frequency.

    

    Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 100
*/

/*
 * APPROACH: Use a hashmap to store the frequency of each digit
 * in nums. Loop through nums once
 * Create a function to check if a number is prime
 * loop throught the frequency hashmap until you find a prime
 * number. If you find one, return true immediately.
 */


public class checkIfAnyElementHasPrimeFrequency_3591 {
    public static boolean isPrime(int num) {
        if (num == 1) {
            return false;
        }
        int divisors = 1;

        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                divisors++;
            }
            if (divisors > 2) {
                return false;
            }
        }
        return true;
    }
    public static boolean checkPrimeFrequency(int[] nums) {
        Map<Integer, Integer> frequency = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (frequency.get(nums[i]) == null) {
                frequency.put(nums[i], 1);
            } else {
                int current = frequency.get(nums[i]);
                current++;
                frequency.put(nums[i], current);
            }
        }

        for (Map.Entry<Integer, Integer> res : frequency.entrySet()) {
            if (isPrime(res.getValue())) {
                return true;
            }
            
        }
        return false;

    }
    public static void main(String[] args) {
        int[] test = {1,2,3,4,5};
        System.out.println(checkPrimeFrequency(test));
        
    }
    
}

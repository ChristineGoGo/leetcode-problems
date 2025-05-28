
import java.util.Arrays;
/*
 * Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.
 * The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
 * Example 1:
 * Input: nums = [2,5,6,9,10]
 * Output: 2
 * Explanation:
 * The smallest number in nums is 2.
 * The largest number in nums is 10.
 * The greatest common divisor of 2 and 10 is 2.
 * Example 2:
 * Input: nums = [7,5,6,8,3]
 * Output: 1
 * Explanation:
 * The smallest number in nums is 3.
 * The largest number in nums is 8.
 * The greatest common divisor of 3 and 8 is 1.
 * Example 3:
 * Input: nums = [3,3]
 * Output: 3
 * Explanation:
 * The smallest number in nums is 3.
 * The largest number in nums is 3.
 * The greatest common divisor of 3 and 3 is 3.
 * Constraints:
 * 2 <= nums.length <= 1000
 * 1 <= nums[i] <= 1000
 */

/*
 * APPROACH: Sort the array and then use a while loop to find a divisor for both
 * the largest and the smallest number
 */

public class greatestCommonDivisorOfArray_1979 {
    public static int findGCD(int[] nums) {
        Arrays.sort(nums);
        int greatestThisFar = nums[0];
        int potentialGreatest = nums[nums.length - 1];
        int start = 1;
        int result = 1;
        while (start <= potentialGreatest) {
            if (greatestThisFar % start == 0 && potentialGreatest % start == 0) {
                result = start;
            }
            start += 1;
        }
        return result;
    }
    public static void main(String[] args) {
        int[] test = {3, 2};
        System.out.println(findGCD(test));
    }
    
}

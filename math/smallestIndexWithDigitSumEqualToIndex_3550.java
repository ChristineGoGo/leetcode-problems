/*
    You are given an integer array nums.

    Return the smallest index i such that the sum of the digits of nums[i] is equal to i.

    If no such index exists, return -1.

    

    Example 1:

    Input: nums = [1,3,2]

    Output: 2

    Explanation:

    For nums[2] = 2, the sum of digits is 2, which is equal to index i = 2. Thus, the output is 2.
    Example 2:

    Input: nums = [1,10,11]

    Output: 1

    Explanation:

    For nums[1] = 10, the sum of digits is 1 + 0 = 1, which is equal to index i = 1.
    For nums[2] = 11, the sum of digits is 1 + 1 = 2, which is equal to index i = 2.
    Since index 1 is the smallest, the output is 1.
    Example 3:

    Input: nums = [1,2,3]

    Output: -1

    Explanation:

    Since no index satisfies the condition, the output is -1.
    

    Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 1000
*/

/*
 * APPROACH: Loop for each number in nums, find the digit sum
 * compare it to the index sum. The first index is the smallest,
 * return it.
 */
public class smallestIndexWithDigitSumEqualToIndex_3550 {
    public static int smallestIndex(int[] nums) {
        int currentSum = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] / 10 > 0) {
                int current = nums[i];
                while (current > 0) {
                    int num = current % 10;
                    currentSum += num;
                    current /= 10;
                }
                if (i == currentSum) {
                    return i;
                }
                currentSum = 0;
            } else if (nums[i] == i) {
                return i;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        int[] test = {1,3, 2};
        System.out.println(smallestIndex(test));
    }

    
}

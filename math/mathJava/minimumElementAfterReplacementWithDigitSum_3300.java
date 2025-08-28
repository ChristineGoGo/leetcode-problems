/*
    You are given an integer array nums.

    You replace each element in nums with the sum of its digits.

    Return the minimum element in nums after all replacements.

    

    Example 1:

    Input: nums = [10,12,13,14]

    Output: 1

    Explanation:

    nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.

    Example 2:

    Input: nums = [1,2,3,4]

    Output: 1

    Explanation:

    nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.

    Example 3:

    Input: nums = [999,19,199]

    Output: 10

    Explanation:

    nums becomes [27, 10, 19] after all replacements, with minimum element 10.

    

    Constraints:

    1 <= nums.length <= 100
    1 <= nums[i] <= 104
*/




public class minimumElementAfterReplacementWithDigitSum_3300 {
    public int findDigitSum(int num) {
        int res = 0;

        while(num > 0) {
            int current = num % 10;
            res += current;
            num /= 10;
        }
        return res;
    }
    public int minElement(int[] nums) {
        int[] replace = new int[nums.length];
        int smallest = 10000;

        for (int i = 0; i < nums.length; i++) {
            int currentSum = findDigitSum(nums[i]);
            replace[i] = currentSum;
        }

        for (int i = 0; i < replace.length; i++) {
            smallest = Math.min(replace[i], smallest);
        }
        return smallest;
    }
    
}

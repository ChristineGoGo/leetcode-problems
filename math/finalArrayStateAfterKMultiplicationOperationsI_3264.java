/*
    You are given an integer array nums, an integer k,
     and an integer multiplier.

    You need to perform k operations on nums. In each operation:

    Find the minimum value x in nums. If there are multiple occurrences 
    of the minimum value, select the one that appears first.

    Replace the selected minimum value x with x * multiplier.
    Return an integer array denoting the final state of nums after
     performing all k operations.

    

    Example 1:

    Input: nums = [2,1,3,5,6], k = 5, multiplier = 2

    Output: [8,4,6,5,6]

    Explanation:

    Operation	Result
    After operation 1	[2, 2, 3, 5, 6]
    After operation 2	[4, 2, 3, 5, 6]
    After operation 3	[4, 4, 3, 5, 6]
    After operation 4	[4, 4, 6, 5, 6]
    After operation 5	[8, 4, 6, 5, 6]
    Example 2:

    Input: nums = [1,2], k = 3, multiplier = 4

    Output: [16,8]

    Explanation:

    Operation	Result
    After operation 1	[4, 2]
    After operation 2	[4, 8]
    After operation 3	[16, 8]
    

    Constraints:

    1 <= nums.length <= 100
    1 <= nums[i] <= 100
    1 <= k <= 10
    1 <= multiplier <= 5
 */


public class finalArrayStateAfterKMultiplicationOperationsI_3264 {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        int current = 0;

        while (current < k ) {
            int smallest = Integer.MAX_VALUE;
            int smallestIndex = 0;
            for (int i = 0; i < nums.length; i++ ) {
                if (nums[i] < smallest) {
                    smallest = nums[i];
                    smallestIndex = i;
                }
            }
            nums[smallestIndex] *= multiplier;
            // System.out.println(Arrays.toString(nums));
            current++;
        }

        return nums;
        
    }
    
}

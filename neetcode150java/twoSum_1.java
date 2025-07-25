import java.util.*;
/*
    Given an array of integers nums and an integer target, 
    return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, 
    and you may not use the same element twice.

    You can return the answer in any order.

    

    Example 1:

    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    Example 2:

    Input: nums = [3,2,4], target = 6
    Output: [1,2]
    Example 3:

    Input: nums = [3,3], target = 6
    Output: [0,1]
    

    Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
    

    Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/
public class twoSum_1 {
    // O(N** 2) Solution
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];

        for (int i = 0; i < nums.length; i++) {
            int current = nums[i];
            int difference = target - nums[i];

            for (int j = i +1; j < nums.length; j++) {
                if (nums[j] == difference) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }
        return result;
        
    }

    // O(1) solution
    // public int[] twoSum(int[] nums, int target) {
    //     int[] result = new int[2];
    //     Map<Integer, Integer> indexes = new HashMap<>();
  

    //     for (int i = 0; i < nums.length; i++) {
    //         indexes.put(nums[i], i);
    //     }

    //     for (int i = 0; i < nums.length; i++) {
    //         int difference = target - nums[i];

    //         if (indexes.get(difference) != null && indexes.get(difference) != i) {
    //             return new int[]{i, indexes.get(difference)};
    //         } 
    //     }
    //     return result;
    // }
    public static void main(String[] args) {
        Map<Integer, int[]> m = new HashMap<>();
        m.put(3, new int[]{2});

    }
    
}

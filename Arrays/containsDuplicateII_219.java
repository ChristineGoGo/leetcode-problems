package Arrays;
/*
    Given an integer array nums and an integer k, return true if there are two
     distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

    

    Example 1:

    Input: nums = [1,2,3,1], k = 3
    Output: true
    Example 2:

    Input: nums = [1,0,1,1], k = 1
    Output: true
    Example 3:

    Input: nums = [1,2,3,1,2,3], k = 2
    Output: false
    

    Constraints:

    1 <= nums.length <= 105
    -109 <= nums[i] <= 109
    0 <= k <= 105

*/

import java.util.HashMap;
import java.util.Map;

public class containsDuplicateII_219 {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        // Use a hashmap to track the current number and index
        // use a boolean as well to track the count of the number

        Map<Integer, Integer> index = new HashMap<>();
        boolean duplicates = false;

        for (int i = 0; i < nums.length; i++) {
            if (index.get(nums[i]) == null) {
                index.put(nums[i], i);
            } else {
                int prev = index.get(nums[i]);
                duplicates = true;
                if ((i - prev) <= k) {
                    return true;
                } else if (duplicates) {
                    index.put(nums[i], i);
                }
            }
        }
        return false;
    }
    
}

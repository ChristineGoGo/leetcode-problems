package hashtable;

public class howManyNumbersAreSmallerThanTheCurrentNumber_1365 {
        /*
    * APPROACH: 1. Brute force 2. Sort the array
    */
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] result = new int[nums.length];
      
        for (int i = 0; i < nums.length; i++) {
            int curr  = 0;
            for (int j = 0; j < nums.length; j++) {  
                if(nums[j] < nums[i]) {
                        curr++;
 
                }
            }
            result[i] = curr;
        }

        return result;
    }
    
}

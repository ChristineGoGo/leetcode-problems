/*
    You are given an integer array nums containing positive integers. 
    We define a function encrypt such that encrypt(x) replaces every digit 
    in x with the largest digit in x. For example, encrypt(523) = 555 and encrypt(213) = 333.

    Return the sum of encrypted elements.

    

    Example 1:

    Input: nums = [1,2,3]

    Output: 6

    Explanation: The encrypted elements are [1,2,3]. The sum of encrypted elements is 1 + 2 + 3 == 6.

    Example 2:

    Input: nums = [10,21,31]

    Output: 66

    Explanation: The encrypted elements are [11,22,33]. The sum of encrypted elements is 11 + 22 + 33 == 66.

    

    Constraints:

    1 <= nums.length <= 50
    1 <= nums[i] <= 1000
*/



public class findTheSumOfEncryptedIntegers_3079 {
    public static int encrypt(int x) {
        String sNum = Integer.toString(x);
        int m = 0;
        String res = "";

        for (int i = 0; i < sNum.length(); i++) {
            int curr = (int) sNum.charAt(i);
            m = Math.max(m, curr);
        }

        char toReplace = (char) m;

        for (int i = 0; i < sNum.length(); i++) {
            res += toReplace;
        }

        int numRes = Integer.parseInt(res);

        return (int) numRes;

    }
    public static int sumOfEncryptedInt(int[] nums) {
        int[] res = new int[nums.length];
        int total = 0;

        for (int i = 0; i < nums.length; i++) {
            res[i] = encrypt(nums[i]); 
        }

        for (int i = 0; i < res.length; i++) {
            total += res[i];
        }
        return total;

    }
    public static void main(String[] args) {
        int[] test = {10, 21, 31};
        System.out.println(sumOfEncryptedInt(test));
        
    }
    
}

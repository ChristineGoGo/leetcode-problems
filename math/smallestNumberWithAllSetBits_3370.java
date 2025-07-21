/*

    You are given a positive number n.

    Return the smallest number x greater than or equal to n, 
    such that the binary representation of x contains only set bits

    Example 1:

    Input: n = 5

    Output: 7

    Explanation:

    The binary representation of 7 is "111".

    Example 2:

    Input: n = 10

    Output: 15

    Explanation:

    The binary representation of 15 is "1111".

    Example 3:

    Input: n = 3

    Output: 3

    Explanation:

    The binary representation of 3 is "11".

    

    Constraints:

    1 <= n <= 1000
*/



public class smallestNumberWithAllSetBits_3370 {
    public String toBinary(int num) {
        String res = "";

        while (num > 0) {
            int curr = num % 2;
            res += Integer.valueOf(curr);
            num /= 2;
        }

        StringBuilder result = new StringBuilder();

        result.append(res);
        result.reverse();

        return result + "";
    }

    public int smallestNumber(int n) {
        int num = n;
        int tracker = 0;

        while (num <= 2000) {
            // System.out.println(num);

            String currBit = toBinary(num);
            boolean allOnes = true;

            // System.out.println(currBit);

            for (int i = 0; i < currBit.length(); i++) {
                String curr = currBit.charAt(i) + "";
                if (!curr.equals("1")) {
                    allOnes = false;
                    
                } 
                tracker++;
            }
            // System.out.println(tracker);
            if (tracker == currBit.length() && allOnes == true) {
                return num;
            }
            num++;
            tracker = 0;
        }
        return num;
    }
    
}

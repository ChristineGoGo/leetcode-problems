/*
    You are given an array of positive integers nums.

    Alice and Bob are playing a game. In the game, Alice can choose either all single-digit 
    numbers or all double-digit numbers from nums, and the rest of the numbers are given to Bob.
    Alice wins if the sum of her numbers is strictly greater than the sum of Bob's numbers.

    Return true if Alice can win this game, otherwise, return false.

    

    Example 1:

    Input: nums = [1,2,3,4,10]

    Output: false

    Explanation:

    Alice cannot win by choosing either single-digit or double-digit numbers.

    Example 2:

    Input: nums = [1,2,3,4,5,14]

    Output: true

    Explanation:

    Alice can win by choosing single-digit numbers which have a sum equal to 15.

    Example 3:

    Input: nums = [5,5,5,25]

    Output: true

    Explanation:

    Alice can win by choosing double-digit numbers which have a sum equal to 25.

    

    Constraints:

    1 <= nums.length <= 100
    1 <= nums[i] <= 99
*/

/*
 * APPROACH: Add up all the single digits and then 
 * all the double digits in the array. Bob only wins
 * if the single digits sum is equal to the double digit sum . 
 * Return false else return true.
 * 1. Initialize two variables to track the single digits
 * and the double digits
 * 2. Loop through the array, convert each digit into a string
 * to get the length, and add to single digit and double digit as 
 * needed.
 */

public class findIfDigitGameCanBeWon_3232 {
    public static boolean canAliceWin(int[] num) {
        int doubleDigits = 0;
        int singleDigits = 0;

        for (int i = 0; i < num.length; i++) {
            // int len = String.valueOf(num[i]).length();
            if ( String.valueOf(num[i]).length() == 2) {
                singleDigits += num[i];

            } else {
                doubleDigits += num[i];
            }
        }
        
        return doubleDigits == singleDigits ? false : true;


    }
    public static void main(String[] args) {
        int[] test1 = {1,2,3,4,10};
        System.out.println(canAliceWin(test1));
    }

    
}

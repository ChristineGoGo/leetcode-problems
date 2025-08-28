/*
    Alice and Bob are playing a game. Initially, Alice has a string word = "a".

    You are given a positive integer k.

    Now Bob will ask Alice to perform the following operation forever:

    Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
    For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".

    Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.

    Note that the character 'z' can be changed to 'a' in the operation.

    

    Example 1:

    Input: k = 5

    Output: "b"

    Explanation:

    Initially, word = "a". We need to do the operation three times:

    Generated string is "b", word becomes "ab".
    Generated string is "bc", word becomes "abbc".
    Generated string is "bccd", word becomes "abbcbccd".
    Example 2:

    Input: k = 10

    Output: "c"

    

    Constraints:

    1 <= k <= 500
*/

/*
 * APPROACH: Use ASCII to convert the letters into integer so as to get the next value
 * in the alphabet character. Continue adding until K characters are reached. Return
 * the kth value.
 */


public class findTheKthCharacterInStringGameI_3304 {
    public static char kthCharacter(int k) {
        int currLen = 0;
        char currChar;
        String result = "a"; 

        while (currLen < k) {
            String nString = "";

            for (int i = 0; i < result.length(); i++) {
                int currInt = (int) result.charAt(i);
                if (currInt >= 122) {
                    currInt = 96;
                }
                currInt++;
                currChar = (char) currInt;
                nString += currChar;
            }

            result += nString;
            currLen = result.length();
        }
        char r = result.charAt(k - 1);
        return r;
    }

    public static void main(String[] args) {
        System.out.println(kthCharacter(10));
    }
    
}

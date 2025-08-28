package stringsjava;

/*
    Given a string s, reverse the string according to the following rules:

    All the characters that are not English letters remain in the same position.
    All the English letters (lowercase or uppercase) should be reversed.
    Return s after reversing it.

    

    Example 1:

    Input: s = "ab-cd"
    Output: "dc-ba"
    Example 2:

    Input: s = "a-bC-dEf-ghIj"
    Output: "j-Ih-gfE-dCba"
    Example 3:

    Input: s = "Test1ng-Leet=code-Q!"
    Output: "Qedo1ct-eeLg=ntse-T!"
    

    Constraints:

    1 <= s.length <= 100
    s consists of characters with ASCII values in the range [33, 122].
    s does not contain '\"' or '\\'.
*/


// APPROACH: Use a right and left pointer to determine to switch or not

public class reverseOnlyLetters_917 {
    public static String reverseOnlyLetters(String s) {
        String result = "";
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            String currLeft = "" + s.charAt(left);
            String currRight = "" + s.charAt(right);

            if (currLeft.is) {

            }
        }
    }

    public static void main(String[] args) {
        System.out.println(reverseOnlyLetters("a-bC-dEf-ghIj"));
        
    }
    
}

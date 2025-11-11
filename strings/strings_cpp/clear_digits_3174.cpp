/*
    You are given a string s.

    Your task is to remove all digits by doing this operation repeatedly:

    Delete the first digit and the closest non-digit character to its left.
    Return the resulting string after removing all digits.

    Note that the operation cannot be performed on a digit that does not have any non-digit character to its left.

    

    Example 1:

    Input: s = "abc"

    Output: "abc"

    Explanation:

    There is no digit in the string.

    Example 2:

    Input: s = "cb34"

    Output: ""

    Explanation:

    First, we apply the operation on s[2], and s becomes "c4".

    Then we apply the operation on s[1], and s becomes "".

    

    Constraints:

    1 <= s.length <= 100
    s consists only of lowercase English letters and digits.
    The input is generated such that it is possible to delete all digits.

*/

#include <iostream>
using namespace std;

// APPROACH: Create a function to check if a character is a digit,
// loop through each item in s if it not a digit add to the result string
// if it is, remove the last character from the result string    
string clearDigits(string s) {
    string result = "";
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        if (isDigit(s[i]) == 1 && result.length() > 0 ) {
            result.pop_back();
        } else {
            result += s[i];
        }
    }
    return result;

}

int isDigit(char c) {
    int curr = c;
    if (curr >= 97 && curr <= 123) {
        return 0;
    }
    return 1;
}




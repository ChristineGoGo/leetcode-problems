/*
    You are given a string s and an integer k.

    Determine if there exists a substring of length exactly k in s that satisfies the following conditions:

    The substring consists of only one distinct character (e.g., "aaa" or "bbb").
    If there is a character immediately before the substring, it must be different from the character in the substring.
    If there is a character immediately after the substring, it must also be different from the character in the substring.
    Return true if such a substring exists. Otherwise, return false.

    

    Example 1:

    Input: s = "aaabaaa", k = 3

    Output: true

    Explanation:

    The substring s[4..6] == "aaa" satisfies the conditions.

    It has a length of 3.
    All characters are the same.
    The character before "aaa" is 'b', which is different from 'a'.
    There is no character after "aaa".
    Example 2:

    Input: s = "abc", k = 2

    Output: false

    Explanation:

    There is no substring of length 2 that consists of one distinct character and satisfies the conditions.

    

    Constraints:

    1 <= k <= s.length <= 100
    s consists of lowercase English letters only.

*/
#include <iostream>
using namespace std;

// APPROACH: Use a fixed sliding window approach to
// find the required substring
bool hasSpecialSubstring(string s, int k) {
    int n = s.length();
    for (int i = 0; i <= n - k; i++) {
        char curr = s[i];
        int distinct = 1;
        // find if substring consists of only one distinct character
        for (int j = i; j < i + k; j++) {
            // cout << "s[j]: " << s[j] << " s[i]: " << s[i] << "\n";
            if (s[j] != curr) {
                distinct = 0;
                break;
            }
        }
        int valid  = 1;
        if (distinct == 1) {
            // cout << "found same charaacters";
            // find if there is different character before the subarray
            if (i > 0 && s[i - 1] == curr) {
                valid = 0;
            }
            // find if there is different character after the subarray
            // or we are at end of subarray
            if (s[i + k] == s[i] && (i + k < n)) {
                    valid = 0;
            }

            if (valid  == 1) {
                return true;
            }
        }

    }
    if (k == n){
        char curr = s[0]; 
        for (int i = 0; i < n; i++) {
            if (s[i] != curr){
                return false;

            }
        }
        return true;
    }


    return false;
    
}




/*

    You are given a license key represented as a string s that consists
     of only alphanumeric characters and dashes. The string is separated 
     into n + 1 groups by n dashes. You are also given an integer k.

    We want to reformat the string s such that each group contains exactly 
    k characters, except for the first group, which could be shorter than k 
    but still must contain at least one character. Furthermore, there must be
    a dash inserted between two groups, and you should convert all lowercase 
    letters to uppercase.

    Return the reformatted license key.

    

    Example 1:

    Input: s = "5F3Z-2e-9-w", k = 4
    Output: "5F3Z-2E9W"
    Explanation: The string s has been split into two parts, each part has 4 characters.
    Note that the two extra dashes are not needed and can be removed.
    Example 2:

    Input: s = "2-5g-3-J", k = 2
    Output: "2-5G-3J"
    Explanation: The string s has been split into three parts, each part has 2
    characters except the first part as it could be shorter as mentioned above.
    

    Constraints:

    1 <= s.length <= 105
    s consists of English letters, digits, and dashes '-'.
    1 <= k <= 104
*/

// APPROACH: Create variables result and idx to store result string and current index position
// Loop through string s
//  For each iteration: if idx is <= k and current character is not a dash, add to result
//                      if conditions are not met set idx back to 0
// return the result string


#include <iostream>

using namespace std;

string licenseKeyFormatting(string s, int k) {
    string res = "";
    int idx = 0;
    int n = s.length();

    for (int i = n - 1; i >= 0;i--) {
        char curr = s[i];
        if(curr != '-' && idx < k) {
            res += toupper(curr);
            idx++;
        } else if(idx == k) {
            res += '-';
            if (curr != '-') {
                res += toupper(curr);
                idx = 1;
            } else {
                idx = 0;
            }
        }
    }

    reverse(res.begin(), res.end());

    idx = 0; 

    while (idx < n) {
        if (idx == 0 && res[idx] == '-') res.erase(idx,1);
        idx++;
    }


    return res;
    
}




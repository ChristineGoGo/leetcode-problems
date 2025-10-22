/*
    You are given a string s consisting of lowercase English letters.

    Your task is to find the maximum difference diff = freq(a1) - freq(a2) 
    between the frequency of characters a1 and a2 in the string such that:

    a1 has an odd frequency in the string.
    a2 has an even frequency in the string.
    Return this maximum difference.

    

    Example 1:

    Input: s = "aaaaabbc"

    Output: 3

    Explanation:

    The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
    The maximum difference is 5 - 2 = 3.
    Example 2:

    Input: s = "abcabcab"

    Output: 1

    Explanation:

    The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
    The maximum difference is 3 - 2 = 1.
    

    Constraints:

    3 <= s.length <= 100
    s consists only of lowercase English letters.
    s contains at least one character with an odd frequency and one with an even frequency.

*/

#include <iostream>
#include <map>
using namespace std;

// APPROACH: Find the frequency of each character in s
// and store in a map
// find the maximum odd frequency and store in a variable
// find the minimum even frequency and store in a variable
// return the difference
int maxDifference(string s) {
    map<char, int> freq;
    int maxOdd = 0;
    int minEven = 100;

    for (char l: s) {
        freq[l]++;
    }

    for (auto vals: freq) {
        if (vals.second % 2 == 0) {
            minEven = vals.second < minEven ? vals.second : minEven;
        } else {
            maxOdd = vals.second > maxOdd ? vals.second : maxOdd;
        }
    }

    return maxOdd - minEven;
    
}




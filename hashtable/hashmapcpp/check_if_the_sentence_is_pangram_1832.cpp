/*
    A pangram is a sentence where every letter of the English alphabet
    appears at least once.

    Given a string sentence containing only lowercase English letters,
    return true if sentence is a pangram, or false otherwise.

    

    Example 1:

    Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
    Output: true
    Explanation: sentence contains at least one of every letter of the
    English alphabet.
    Example 2:

    Input: sentence = "leetcode"
    Output: false
    

    Constraints:

    1 <= sentence.length <= 1000
    sentence consists of lowercase English letters.

*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;


// APPROACH: create frequency map to compare to all the letters
// in the alphabet
bool checkIfPangram(string sentence) {
    vector<char> alphabets = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h','i','j', 'k','l','m', 'n','o','p','q','r','s','t','u','v','w', 'x', 'y', 'z'};
    map<char, int> freq;

    for( char c: sentence) {
        freq[c]++;

    }

    for (char letter: alphabets) {
        if (freq[letter] < 1) {
            return false;
        }
    }

    return true;
    
    }
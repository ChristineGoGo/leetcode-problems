/*
    In an alien language, surprisingly, they also use English lowercase letters,
    but possibly in a different order. The order of the alphabet is some permutation
    of lowercase letters.

    Given a sequence of words written in the alien language, and the order of the alphabet,
    return true if and only if the given words are sorted lexicographically in this alien language.

    

    Example 1:

    Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
    Output: true
    Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
    Example 2:

    Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
    Output: false
    Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence
    the sequence is unsorted.
    Example 3:

    Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
    Output: false
    Explanation: The first three characters "app" match, and the second string is shorter
    (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where 
    '∅' is defined as the blank character which is less than any other character (More info).
    

    Constraints:

    1 <= words.length <= 100
    1 <= words[i].length <= 20
    order.length == 26
    All characters in words[i] and order are English lowercase letters.
*/
#include <iostream>
#include <map>

using namespace std;

    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> alienDictionary;
        int result;

        // add the alien alphabet into a dictionary
        for (int i = 0; i < order.size(); i++) {
            alienDictionary[order[i]] = i;
        }

        //compare each word to see if they are sorted
        for (int i = 0; i < words.size() - 1; i++) {
            
            for (int j = 0; j < words[i].size(); j++) {
                // cout << words[i + 1].size();
                //check the length of the word exceeds the later word
                if (j >= words[i + 1].size()) {
                    return false;
                }

                // compare the current letters within bound
                if (words[i][j] != words[i + 1][j]) {
                    if (alienDictionary[words[i][j]] > alienDictionary[words[i + 1][j]]) {
                        return false;
                    } else {
                        break;
                    }
                }
            }
        }

        return true;

        
    }

int main() {
    map<char, int> m;
    m['a'] = 1;
    m['b'] = 2;

    cout << m['p'];
    cout << m['a'];
}





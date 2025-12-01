/*

    A substring is a contiguous (non-empty) sequence of characters within a string.

    A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 
    'o', and 'u') and has all five vowels present in it.

    Given a string word, return the number of vowel substrings in word.

    

    Example 1:

    Input: word = "aeiouu"
    Output: 2
    Explanation: The vowel substrings of word are as follows (underlined):
    - "aeiouu"
    - "aeiouu"
    Example 2:

    Input: word = "unicornarihan"
    Output: 0
    Explanation: Not all 5 vowels are present, so there are no vowel substrings.
    Example 3:

    Input: word = "cuaieuouac"
    Output: 7
    Explanation: The vowel substrings of word are as follows (underlined):
    - "cuaieuouac"
    - "cuaieuouac"
    - "cuaieuouac"
    - "cuaieuouac"
    - "cuaieuouac"
    - "cuaieuouac"
    - "cuaieuouac"
    

    Constraints:

    1 <= word.length <= 100
    word consists of lowercase English letters only.

*/

// APPROACH: Create variable to store the total count of vowel substring
// create a set to store all the vowels
// loop through each character in the string word
//      if the vowel count is 5 add to total else if 
//         character is not a vowel exit
// return the total count of the vowels found

#include <iostream>
#include <map>
using namespace std;

int countVowelSubstrings(string word) {
    int tot = 0;
    int n = word.length();
    set<char> vowelsFound;

    for (int i = 0; i < n - 4;  i++) {
        vowelsFound.clear();

        for (int j = i; j < n; j++) {
            char curr = word[j];
            if (curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u') {
                vowelsFound.insert(word[j]);
                if (vowelsFound.size() == 5) tot++;
            } else {
                break;
            }
        }
    }

    return tot;
    
}






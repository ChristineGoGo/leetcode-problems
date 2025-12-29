/*

    You are given an array of strings words and a string chars.

    A string is good if it can be formed by characters from chars
    (each character can only be used once for each word in words).

    Return the sum of lengths of all good strings in words.


    Example 1:

    Input: words = ["cat","bt","hat","tree"], chars = "atach"
    Output: 6
    Explanation: The strings that can be formed are "cat" and "hat"
    so the answer is 3 + 3 = 6.
    Example 2:

    Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
    Output: 10
    Explanation: The strings that can be formed are "hello" and "world" so
    the answer is 5 + 5 = 10.


    Constraints:

    1 <= words.length <= 1000
    1 <= words[i].length, chars.length <= 100
    words[i] and chars consist of lowercase English letters.

*/


// APPROACH: Create a map to count the characters in chars and their equivalent
// frequency,create a variable to store the sum of length of the good strings in words.
// Loop through each word in words, create a frequency map for also each character for each word in words
// For each word in word if all the letter in word have atleast a 1
// frequency in chars add the length of the string to the sum.
// return the sum of the good strings in words
int countCharacters(vector<string>& words, string chars) {
    map<char, int> charsFreq;

    int totS = 0;

    for (char c: chars) {
        charsFreq[c]++;
    }

    for (string word: words) {
        map<char, int> currFreq;
        int isGood = 0;
        // populate word frequency
        for (char c: word) {
            currFreq[c]++;
        }
        // verify if word occurs in chars
        for (char c: word) {
            isGood = 0;
            for (auto vals: charsFreq) {
                if (vals.first == c) {
                    if (vals.second >= currFreq[c]) {
                        isGood = 1;
                        break;
                    }
                }
            }
            if (isGood == 0) {
                break;
            }
        }
        // add to sum of lengths of good strings if neccessary
        if (isGood == 1) {
            // cout << "good word is currently: " << word << " ";
            totS += word.size();
        }
    }

    return totS;
}


/*

    Given an array of strings words, return the words that can be typed using letters
    of the alphabet on only one row of American keyboard like the image below.

    Note that the strings are case-insensitive, both lowercased and uppercased of the same
    letter are treated as if they are at the same row.

    In the American keyboard:

        the first row consists of the characters "qwertyuiop",
        the second row consists of the characters "asdfghjkl", and
        the third row consists of the characters "zxcvbnm".


    Example 1:

        Input: words = ["Hello","Alaska","Dad","Peace"]

        Output: ["Alaska","Dad"]

        Explanation:

        Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.

    Example 2:

        Input: words = ["omk"]

        Output: []

    Example 3:

        Input: words = ["adsdf","sfd"]

        Output: ["adsdf","sfd"]


    Constraints:

        1 <= words.length <= 20
        1 <= words[i].length <= 100
        words[i] consists of English letters (both lowercase and uppercase).
*/

//------------------------------------------------------------------------------------------------------


/*
    Intuition
    Use a vector to map the rows and strings for keyboard.

    # Approach
    1. Create a vector to store the results
    2. Create a vector of stringto store the keyboard rows
    3. Loop for each word in words
        a) loop for each character in the word string.
            i)Add the rows of each character into a vector
            ii) Track the row numbers with a boolean value
        b) loop for each keyboard character in each row populating rows vector
        c) loop for each row value collected and set boolean to false if the rows
        are not all the same. Add the word to the results if the boolean is true
    4. Return the results

    # Complexity
    - Time complexity:
    O(n * m) n is length of the words, m is length of keyboard string for each row
    - Space complexity:
    O(1) the words that meet the requirement are fixed

*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        vector<string> keyboard(3, "");
        keyboard[0] = "qwertyuiop";
        keyboard[1] = "asdfghjkl";
        keyboard[2] = "zxcvbnm";

        for (string word: words){
            vector<int> rows;
            bool allSame = true;
            for (char c: word) {
                for (int i = 0; i < keyboard.size(); i++) {
                    for (char c1: keyboard[i]) {
                        if (c1 == (char)tolower(c)) rows.push_back(i);
                    }
                }
            }
            for (int i = 0; i < rows.size() - 1; i++){
                if (rows[i] != rows[i + 1] ) {
                    allSame = false;
                }
            }
            if (allSame) result.push_back(word);
        }

        return result;
    }
};


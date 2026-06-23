/*
    Given an array of string words, return all strings in words that are
    a substring of another word. You can return the answer in any order.


    Example 1:

        Input: words = ["mass","as","hero","superhero"]
        Output: ["as","hero"]
        Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
        ["hero","as"] is also a valid answer.

    Example 2:

        Input: words = ["leetcode","et","code"]
        Output: ["et","code"]
        Explanation: "et", "code" are substring of "leetcode".

    Example 3:

        Input: words = ["blue","green","bu"]
        Output: []
        Explanation: No string of words is substring of another string.


    Constraints:
        1 <= words.length <= 100
        1 <= words[i].length <= 30
        words[i] contains only lowercase English letters.
        All the strings of words are unique.

*/

// Create a vector to store the results
// Create a function to determine if a word is
// a substring of another
// Loop for each word in words
//      - deternine the substring of each word
//         add to the result
vector<string> stringMatching(vector<string>& words) {
    set<string> result;
    vector<string> sResult;

    // loop to determine the substrings
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words.size(); j++) {
            if (words[i].size() > words[j].size()) {
                for (int k = 0; k < words[i].size(); k++) {
                    bool found = true;
                    for (int l = 0; l < words[j].size();l++) {
                        if (k + l >= words[i].size() ||
                            words[i][k + l] != words[j][l])
                        {
                                found = false;
                                break;
                        }
                    }
                    if (found){
                        result.insert(words[j]);
                        break;
                    }
                }
            }
        }

    }
    for (string s: result) {
        sResult.push_back(s);
    }
    return sResult;
}







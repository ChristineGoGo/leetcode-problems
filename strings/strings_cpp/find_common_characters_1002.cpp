/*
    Given a string array words, return an array of all characters that
    show up in all strings within the words (including duplicates). 
    You may return the answer in any order.

    

    Example 1:

    Input: words = ["bella","label","roller"]
    Output: ["e","l","l"]
    Example 2:

    Input: words = ["cool","lock","cook"]
    Output: ["c","o"]
    

    Constraints:

    1 <= words.length <= 100
    1 <= words[i].length <= 100
    words[i] consists of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
 
vector<string> commonChars(vector<string>& words){
    vector<int> commonChars(26), currentChars(26);
    vector<string> res;

    int n = words.size();
    
    // add common characters from the first word
    for(char curr: words[0]) {
        commonChars[curr - 'a']++;
    }

    // loop through the words finding the common letters
    for (int i = 1; i < n; i++) {
        fill(currentChars.begin(), currentChars.end(), 0);

        // fill the frequency of the current characters
        for (int j = 0; j < words[i].size(); j++) {
            currentChars[words[i][j] - 'a']++;
        }

        // find the frequency of the common characters

        for (int k = 0; k <26; k++) {
            commonChars[k] = min(commonChars[k], currentChars[k]);
        }
    }
    
    // populate the results array
    for (int i = 0; i < 26; i++) {
        char currChar = i + 97;
        string s = {currChar};
        for (int j = 0; j < commonChars[i]; j ++ ) {
            res.push_back(s);
        }
    }

    return res;
}


int main() {
    vector<string> words = {"cool", "lock", "cook"};
    vector<string> res = commonChars(words);

    for (string curr: res) {
        cout << curr << " ";
        cout << "\n";
    }
    
    return 0;
}






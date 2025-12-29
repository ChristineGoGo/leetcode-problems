/*
    Given a string text, you want to use the characters of text
    to form as many instances of the word "balloon" as possible.

    You can use each character in text at most once. Return the
    maximum number of instances that can be formed.

    

    Example 1:



    Input: text = "nlaebolko"
    Output: 1
    Example 2:



    Input: text = "loonbalxballpoon"
    Output: 2
    Example 3:

    Input: text = "leetcode"
    Output: 0
    

    Constraints:

    1 <= text.length <= 104
    text consists of lower case English letters only.
*/

// APPROACH: count frequency of letters in text and compare to that of balloon

#include <iostream>
#include <string>
#include <map>

using namespace std;

int maxNumberOfBalloons(string text) {
    int tracker = 0;
    int ballonLetters = 0;
    string b = "balloon";
    int n = text.length();
    bool satisfy = true;

    map<char, int> frequency;

    for(int i =0; i< n; i++) {
        if (frequency[text[i]] == 0) {
            frequency[text[i]] = 1;
        } else {
            frequency[text[i]]++;
        }
    }


    while (satisfy) {
            for (char i: b) {
                int curr = frequency[i];
                if (curr <= 0) {
                    satisfy = false;
                    return tracker;
                }
                frequency[i]--;
            }
            
            tracker++;
    }
    return tracker;
    
    
}
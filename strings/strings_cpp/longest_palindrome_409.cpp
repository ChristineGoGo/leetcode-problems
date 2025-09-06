/*
    Given a string s which consists of lowercase or uppercase letters, return the length of 
    the longest palindrome that can be built with those letters.

    Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

    Example 1:

    Input: s = "abccccdd"
    Output: 7
    Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
    Example 2:

    Input: s = "a"
    Output: 1
    Explanation: The longest palindrome that can be built is "a", whose length is 1.
    

    Constraints:

    1 <= s.length <= 2000
    s consists of lowercase and/or uppercase English letters only.

*/
#include <iostream>
#include <map>

using namespace std;

int longestPalindrome(string s) {
    // create map to store the frequency
    int count = 0;
    int extra = 0;
    int n = s.size();
    map<char, int> frequency;

    for (int i = 0; i < n; i++) {
        if  (frequency[s[i]] == 0) {
            
            frequency[s[i]] = 1;
        } else {
            frequency[s[i]]++;
        }
    }

    // find the even pairs add to the count
    for (auto items : frequency) {
        int curr = items.second;
        int toAdd;

        if (items.second >= 2) {
            
            count = count + (items.second - (items.second % 2));
            
        }

        if (curr % 2 != 0) {
            extra++;
        }
    }
    
    return extra > 0 ? count + 1: count;
}

int main() {
    string s = "name";
    map<char, int> freq; 
    freq[s[0]] = 1;

    for (auto item : freq) {
        cout << item.second;
    }

    cout << 1 / 2; 
}




/*
    You are given a 0-indexed array of string words and
    two integers left and right.

    A string is called a vowel string if it starts with
    a vowel character and ends with a vowel character where
    vowel characters are 'a', 'e', 'i', 'o', and 'u'.

    Return the number of vowel strings words[i] where i belongs
    to the inclusive range [left, right].


    Example 1:

    Input: words = ["are","amy","u"], left = 0, right = 2
    Output: 2
    Explanation:
    - "are" is a vowel string because it starts with 'a' and ends with 'e'.
    - "amy" is not a vowel string because it does not end with a vowel.
    - "u" is a vowel string because it starts with 'u' and ends with 'u'.
    The number of vowel strings in the mentioned range is 2.
    Example 2:

    Input: words = ["hey","aeo","mu","ooo","artro"], left = 1, right = 4
    Output: 3
    Explanation:
    - "aeo" is a vowel string because it starts with 'a' and ends with 'o'.
    - "mu" is not a vowel string because it does not start with a vowel.
    - "ooo" is a vowel string because it starts with 'o' and ends with 'o'.
    - "artro" is a vowel string because it starts with 'a' and ends with 'o'.
    The number of vowel strings in the mentioned range is 3.


    Constraints:

    1 <= words.length <= 1000
    1 <= words[i].length <= 10
    words[i] consists of only lowercase English letters.
    0 <= left <= right < words.length



*/


// APPROACH: Create a function that checks if a word is a vowel
// string. Create variable to store the number of vowel strings
//  Loop in words from index left to index right if a word is a vowel
//  string add to the number of vowels strings
// return the total number of vowel strings

int isVowelString(string s) {
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int n = s.length(), sv = 0, ev = 0;

    for( int i = 0; i < n; i++) {
        for (char vowel: vowels) {
            if (i == 0 && s[i] == vowel || i == n - 1 && s[i] == vowel) {
                if (i == 0) sv = 1;
                if (i == n - 1) ev = 1;
            }
        }
    }

    return sv && ev;
}

int vowelStrings(vector<string>& words, int left, int right) {
    int totVow = 0;

    while ( left <= right) {
        if (isVowelString(words[left]) == 1) totVow++;
        left++;
    }

    return totVow;
}


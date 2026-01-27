/*
    You are given an array of strings words and a string pref.

    Return the number of strings in words that contain pref as a prefix.

    A prefix of a string s is any leading contiguous substring of s.

    

    Example 1:

    Input: words = ["pay","attention","practice","attend"], pref = "at"
    Output: 2
    Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
    Example 2:

    Input: words = ["leetcode","win","loops","success"], pref = "code"
    Output: 0
    Explanation: There are no strings that contain "code" as a prefix.
    

    Constraints:

        1 <= words.length <= 100
        1 <= words[i].length, pref.length <= 100
        words[i] and pref consist of lowercase English letters.

*/




// APPROACH: Create variable to store the count of strings with the same prefix
// Create variable to store length of pref
// Loop through the words comparing their prefixes to pref adding
// 1 to result every time there is a match
int prefixCount(vector<string>& words, string pref) {
    map<string, string> prefs;
    int n = pref.length(); int tot = 0;


    for (string word: words) {
        string curr = "";
        if (word.size() >= n) {
            for (int i = 0; i < n; i++) curr += word[i];
        }

        if (curr == pref) tot++;
    }

    return tot;
}


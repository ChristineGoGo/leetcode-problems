/*

    You are given a string s consisting of lowercase English letters,
    and an integer k.

    Your task is to delete some (possibly none) of the characters in
    the string so that the number of distinct characters in the resulting
    string is at most k.

    Return the minimum number of deletions required to achieve this.

    

    Example 1:

    Input: s = "abc", k = 2

    Output: 1

    Explanation:

    s has three distinct characters: 'a', 'b' and 'c', each with a frequency of 1.
    Since we can have at most k = 2 distinct characters, remove
    all occurrences of any one character from the string.
    For example, removing all occurrences of 'c' results in at most
    k distinct characters. Thus, the answer is 1.
    Example 2:

    Input: s = "aabb", k = 2

    Output: 0

    Explanation:

    s has two distinct characters ('a' and 'b') with frequencies of 2
    and 2, respectively.
    Since we can have at most k = 2 distinct characters, no deletions
    are required. Thus, the answer is 0.
    Example 3:

    Input: s = "yyyzz", k = 1

    Output: 2

    Explanation:

    s has two distinct characters ('y' and 'z') with frequencies of 3
    and 2, respectively.
    Since we can have at most k = 1 distinct character, remove all 
    occurrences of any one character from the string.
    Removing all 'z' results in at most k distinct characters. Thus,
    the answer is 2.
    

    Constraints:

    1 <= s.length <= 16
    1 <= k <= 16
    s consists only of lowercase English letters.

*/
// APPROACH: Use a map to store the frequency of the letters
// in s

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int minDeletion(string s, int k) {
    int deletions = 0;
    vector<int> total;
    map<char, int> freq;

    for (char c: s) {
        freq[c]++;
    }

    for  (auto item: freq) {
        total.push_back(item.second);
    }

    stable_sort(total.begin(), total.end());
    
    int differences = freq.size() - k;
    int index = 0;
    while (differences > 0) {
        deletions += total[index];
        index++;
        differences--;
    }

    return deletions;

    
}


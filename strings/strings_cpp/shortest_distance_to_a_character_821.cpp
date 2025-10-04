/*
    Given a string s and a character c that occurs in s, return an array of
    integers answer where answer.length == s.length and answer[i] is the 
    distance from index i to the closest occurrence of character c in s.

    The distance between two indices i and j is abs(i - j), where abs is
    the absolute value function.

    

    Example 1:

    Input: s = "loveleetcode", c = "e"
    Output: [3,2,1,0,1,0,0,1,2,2,1,0]
    Explanation: The character 'e' appears at indices 3, 5, 6,
    and 11 (0-indexed).
    The closest occurrence of 'e' for index 0 is at index 3, so
    the distance is abs(0 - 3) = 3.
    The closest occurrence of 'e' for index 1 is at index 3,
    so the distance is abs(1 - 3) = 2.
    For index 4, there is a tie between the 'e' at index 3 and 
    the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
    The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.
    Example 2:

    Input: s = "aaab", c = "b"
    Output: [3,2,1,0]
    

    Constraints:

    1 <= s.length <= 104
    s[i] and c are lowercase English letters.
    It is guaranteed that c occurs at least once in s.
*/

#include <iostream>
#include <limits.h>
using namespace std;


// APPROACH: 1. Create array to store the result.
// 2. Loop through each character in the string
//     - loop to find the closest c character on the left side of
//       the current character
//     - loop to find the closest c character on the right side of
//       the current character
//    - add the closest index to the results array.
// 3. Return the result array
vector<int> shortestToChar(string s, char c) {
    int n = s.length();
    
    vector<int> result;
// find the closest on the right side
    for (int i = 0; i < n; i++) {
        int start = i;
        int end = n - 1;
        int closest = 104;

        while (start <= end) {
            if (s[i] == c) {
                closest = 0;
                break;
            }
            if (s[end] == c) {
                int current = end - i;
                if (current < closest) {
                    closest = current;
                }
            }
            
            end--;
        }
        cout << closest << endl;
        result.push_back(closest);

    }
    // find the closest on the left side
    for (int i = 0; i < n; i++) {
        int start = 0;
        int closest  = result[i];

        while (start < i) {
            if (s[start] == c) {
                int current = i - start;
                if (current < closest) {
                    closest = current;
                }
            }
            start++;
        }
        result[i] = closest;
    }
    return result;
}


int main() {
    vector<int> res = shortestToChar("loveleetcode", 'e');
    for (int num : res) {
        cout << num << " ";
    }
    
    return 0;
}


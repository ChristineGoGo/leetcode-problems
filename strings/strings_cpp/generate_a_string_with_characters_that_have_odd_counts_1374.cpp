/*
    Given an integer n, return a string with n characters such that
    each character in such string occurs an odd number of times.

    The returned string must contain only lowercase English letters. 
    If there are multiples valid strings, return any of them.  

    

    Example 1:

    Input: n = 4
    Output: "pppz"
    Explanation: "pppz" is a valid string since the character 'p' occurs 
    three times and the character 'z' occurs once. Note that there are many 
    other valid strings such as "ohhh" and "love".
    Example 2:

    Input: n = 2
    Output: "xy"
    Explanation: "xy" is a valid string since the characters 'x' and 'y' occur
    once. Note that there are many other valid strings such as "ag" and "ur".
    Example 3:

    Input: n = 7
    Output: "holasss"
    

    Constraints:

    1 <= n <= 500

*/


// APPROACH: Determine where to start the new string(char = 97 --- a)
// loop from the first odd number(n - 1 )or i, until 0 adding each letter
// i times to the result string. Return result 

#include <iostream>
using namespace std;



string generateTheString(int n) {
    string res = "";
    int idx = n;
    char toAdd = 97;

    while (idx > 0) {
        if (idx % 2 != 0) {
            int start = 0;
            while (start < idx) {
                res += toAdd;
                start++;
            }
            idx -= start;
        } else {
            int start = 0;
            while (start % 2 == 0) {
                res += toAdd;
                start++;
            }
            
            toAdd++;
            idx -= start;
        }
    }
    return res;

}








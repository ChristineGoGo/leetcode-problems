/*

    Given a positive integer, check whether it has alternating bits:
    namely, if two adjacent bits will always have different values.

    

    Example 1:

    Input: n = 5
    Output: true
    Explanation: The binary representation of 5 is: 101
    Example 2:

    Input: n = 7
    Output: false
    Explanation: The binary representation of 7 is: 111.
    Example 3:

    Input: n = 11
    Output: false
    Explanation: The binary representation of 11 is: 1011.
    

    Constraints:

    1 <= n <= 2**31 - 1

*/

#include <iostream>
using namespace std;

//APPROACH: Convert integer to binary. Loop through the 
// binary and return false if any adjacent has the same values
bool hasAlternatingBits(int n) {
    string res = toBinary(n);
    int s = res.length();

    for (int i = 0; i < s - 1; i++) {
        if (res[i] == res[i + 1]) return false;
    }

    return true;
    
}
string toBinary(int num) {
    string result = "";

    while (num > 0 ) {
        int curr = num % 2;
        string res = to_string(curr);
        result += res;
        num /= 2;
    }

    reverse(result.begin(), result.end());
    return result;
}





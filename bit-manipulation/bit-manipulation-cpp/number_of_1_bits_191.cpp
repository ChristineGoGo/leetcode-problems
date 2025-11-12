/*


    Given a positive integer n, write a function that returns the number of set bits
    in its binary representation (also known as the Hamming weight).

    

    Example 1:

    Input: n = 11

    Output: 3

    Explanation:

    The input binary string 1011 has a total of three set bits.

    Example 2:

    Input: n = 128

    Output: 1

    Explanation:

    The input binary string 10000000 has a total of one set bit.

    Example 3:

    Input: n = 2147483645

    Output: 30

    Explanation:

    The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

    

    Constraints:

    1 <= n <= 231 - 1
    

    Follow up: If this function is called many times, how would you optimize it?

*/

#include <iostream>
using namespace std;
// APPROACH: Convert n into binary count all the ones in the
// binary presentation and return them
int hammingWeight(int n) {
    string binary = "";
    int tot = 0;

    // convert to binary
    while (n > 0) {
        int curr = n % 2;
        // cout << "curr:" << " " << curr << " ";
        char c = curr + '0';
        // cout << "c:" << c << " ";
        binary += c;

        n /= 2;
    }

    for (char c: binary) {
        if (c == '1') {
            tot++;
        }
    }

    return tot;


    
}


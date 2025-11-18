/*

    You are given a positive integer n.

    Return the integer obtained by removing all zeros from the decimal representation of n.

    

    Example 1:

    Input: n = 1020030

    Output: 123

    Explanation:

    After removing all zeros from 1020030, we get 123.

    Example 2:

    Input: n = 1

    Output: 1

    Explanation:

    1 has no zero in its decimal representation. Therefore, the answer is 1.

    

    Constraints:

    1 <= n <= 10 ** 15

*/
#include <iostream>
using namespace std;

// APPROACH: Keep dividing n by 10 and n % 10 to populate the result
long long removeZeros(long long n) {
    long result = 0;
    long times = 1;

    while (n > 0) {
        long curr = n % 10;
        if (curr != 0) {
            result += (times * curr);
            times *= 10;
        }
        n /= 10;
    }

    return result;
    
}









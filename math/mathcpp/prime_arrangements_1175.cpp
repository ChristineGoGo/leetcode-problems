/*

    Return the number of permutations of 1 to n so that prime
    numbers are at prime indices (1-indexed.)

    (Recall that an integer is prime if and only if it is greater than 1,
     and cannot be written as a product of two positive integers both smaller than it.)

    Since the answer may be large, return the answer modulo 10^9 + 7.

    

    Example 1:

    Input: n = 5
    Output: 12
    Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is 
    not because the prime number 5 is at index 1.
    Example 2:

    Input: n = 100
    Output: 682289015
    

    Constraints:

    1 <= n <= 100
*/


#include <iostream>
using namespace std;

// APPROACH: Find the factorial of the number of prime
// numbers from 0 to num multipled by the factorial of the
// composites. Return the answer modulus 10 ^ 9 + 7
int isPrime(int num) {
    for (int i = 1; i < num; i++) {
        if (i != 1 && num % i == 0) return 0;
    }

    return 1;
}


int numPrimeArrangements(int num) {
    long long totalPrimes = 0;
    vector<int> primes;
    unsigned long long M = 1000000007;
    // count the number of primes
    for (int i = 2; i <= num; i++) {
        if (isPrime(i) == 1) {
            totalPrimes++;
            primes.push_back(i);
        }
    }

    // find the composites
    long long composites = num - totalPrimes;

    // find the prime factorial
    long long fp = 1;
    for (int i = 1; i <= totalPrimes; i++){
        fp = (fp * i) % M;
    }

    // find the composite factorial
    long long cp = 1;
    for (int i = 1; i <= composites; i++){
        cp = (cp * i) % M;
    }



    return (cp * fp) % M;
}




int main() {
    cout << numPrimeArrangements(50);
    return 0;
}



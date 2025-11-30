/*

    You are given an integer array deck where deck[i] represents the number written on the ith card.

    Partition the cards into one or more groups such that:

    Each group has exactly x cards where x > 1, and
    All the cards in one group have the same integer written on them.
    Return true if such partition is possible, or false otherwise.

    

    Example 1:

    Input: deck = [1,2,3,4,4,3,2,1]
    Output: true
    Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
    Example 2:

    Input: deck = [1,1,1,2,2,2,3,3]
    Output: false
    Explanation: No possible partition.
    

    Constraints:

    1 <= deck.length <= 10 ** 4
    0 <= deck[i] < 10 ** 4

*/

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

//  APPROACH: Use a hashmap to count the occurences of 
// each number, find gcd of all the occurences. If it is greater than 1 return
// true, else just return false.

bool hasGroupsSizeX(vector<int>& deck) {
    map<int, int> freq;

    stable_sort(deck.begin(), deck.end());

    // find the frequencies
    for (int num: deck) {
        freq[num]++;
    }

    int standard = freq[deck[0]];
    // find the GCD
    for (auto num: freq) {
        standard = gcd(standard, num.second);
    }

    if (standard < 2) return false;
    return true;

    
}



// FIRST RECURSION FUNCTION AFTER 7 YEARS CODING! WHOAAAA!!!
// EUCLIDIAN ALGORITHM -- will use standard GDC function though JK!
int findGCD(int a, int b) {

    if (a == 0 || b == 0) {
        if (a == 0) return b;
        if (b == 0) return a;
    } 
    int bigger = max(a, b);
    int smaller = min(a, b);
    int rem = bigger % smaller;
    int res = findGCD(smaller, rem);

    return res;
 
}


int main() {
    cout <<  findGCD(90, 3);
    return 0;
}




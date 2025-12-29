/*

    Given a list of dominoes, dominoes[i] = [a, b] is equivalent to
    dominoes[j] = [c, d] if and only if either (a == c and b == d),
    or (a == d and b == c) - that is, one domino can be rotated to be
    equal to another domino.

    Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length,
    and dominoes[i] is equivalent to dominoes[j].



    Example 1:

    Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
    Output: 1
    Example 2:

    Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
    Output: 3


    Constraints:

    1 <= dominoes.length <= 4 * 10**4
    dominoes[i].length == 2
    1 <= dominoes[i][j] <= 9

*/

#include <iostream>
#include <map>

using namespace std;

// APPROACH: Hashmap. dominoes[i] is equivalent to dominoes[j]
// if dominoes[j] is equal to dominoes[i] or dominoes[j] is dominoes[i]
// flipped.So basically, we can utilize sorting to find the equivalent
// dominoes for each entry.
// loop for each item in dominoes, find the smallest item, add to string
// find the biggest item, add to string. Add to the total pairs if the item
// is already in the hashmap, add the item into the hashmap
// return the total pairs calculated

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int totPairs = 0;
    map<string, int> freq;

    for(vector<int> domino: dominoes) {
        int a = min(domino[0], domino[1]);
        int b = max(domino[0], domino[1]);
        string curr  = to_string(a) + to_string(b);

        totPairs += freq[curr];

        freq[curr]++;
    }

    return totPairs;

}


int main() {
    vector<vector<int>> dominoes = {{1, 2}, {2, 3}, {1, 2}, {2, 1}};

    cout << numEquivDominoPairs(dominoes);
    return 0;
}












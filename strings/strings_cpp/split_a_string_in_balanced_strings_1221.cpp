/*
    Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

    Given a balanced string s, split it into some number of substrings such that:

    Each substring is balanced.
    Return the maximum number of balanced strings you can obtain.


    Example 1:

    Input: s = "RLRRLLRLRL"
    Output: 4
    Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
    Example 2:

    Input: s = "RLRRRLLRLL"
    Output: 2
    Explanation: s can be split into "RL", "RRRLLRLL", each substring contains same number of 'L' and 'R'.
    Note that s cannot be split into "RL", "RR", "RL", "LR", "LL", because the 2nd and 5th substrings are not balanced.
    Example 3:

    Input: s = "LLLLRRRR"
    Output: 1
    Explanation: s can be split into "LLLLRRRR".


    Constraints:

    2 <= s.length <= 1000
    s[i] is either 'L' or 'R'.
    s is a balanced string.

*/


// APPROACH: Track each R and L with a variable(currR),
// also, track the total balanced strings(tot)
// add 1 each time we encounter a 'R' and subtract 1
// each time we encounter an 'L. When currR is 0, we
// have a balanced string, add to the total balanced strings
// return tot
int balancedStringSplit(string s) {
    int tot = 0,currR = 0;

    for (char c: s) {
        currR = c == 'R'? ++currR : --currR;
        if (currR == 0) tot++;
    }

    return tot;

}






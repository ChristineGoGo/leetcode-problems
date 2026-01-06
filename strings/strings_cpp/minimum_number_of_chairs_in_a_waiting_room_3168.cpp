/*

    You are given a string s. Simulate events at each second i:

    If s[i] == 'E', a person enters the waiting room and takes one of the chairs in it.
    If s[i] == 'L', a person leaves the waiting room, freeing up a chair.
    Return the minimum number of chairs needed so that a chair is available for every
    person who enters the waiting room given that it is initially empty.


    Example 1:

    Input: s = "EEEEEEE"

    Output: 7

    Explanation:

    After each second, a person enters the waiting room and no person leaves it.
    Therefore, a minimum of 7 chairs is needed.

    Example 2:

    Input: s = "ELELEEL"

    Output: 2

*/

// APPROACH: The minimum chairs one can have is 1. So
// set a variable(chairs = 1). Loop while the event
// is less than the total events. Add one to total
// chairs when a person enters and subtract 1 when they leave
// if we get to negative chairs start all over but add minimum by 1
// return the ending minimum value
int minimumChairs(string s) {
    int totChairs = 1, curr = 1;
    int start = 0, n = s.size();
    while (start < n) {
        if (s[start] == 'E'){
            --totChairs;
        } else {
            ++totChairs;
        }
        if (totChairs <= 0) {
            curr++;
            totChairs = curr;
            start = 0;
        } else {
            start++;
        }

    }
    return curr - 1;
}






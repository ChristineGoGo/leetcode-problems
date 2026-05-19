/*

    There is a circle of red and blue tiles. You are given an array of integers colors.
    The color of tile i is represented by colors[i]:

        colors[i] == 0 means that tile i is red.
        colors[i] == 1 means that tile i is blue.
        Every 3 contiguous tiles in the circle with alternating colors
        (the middle tile has a different color from its left and right tiles) is called an alternating group.

    Return the number of alternating groups.

    Note that since colors represents a circle, the first and the last tiles are
    considered to be next to each other.


    Example 1:

    Input: colors = [1,1,1]

    Output: 0

    Example 2:

    Input: colors = [0,1,0,0,1]

    Output: 3

    Constraints:

        3 <= colors.length <= 100
        0 <= colors[i] <= 1
*/
// APPROACH: Create variable to store the total alternating groups
// Loop for each color in colors(index)
//  - if the index is 0, determine if values at index n -1 (n is length of colors)
//    and 1 are the same but different from the current index value
//  - if the index is n - 1 determine if the values at index 0 and n - 2 are different
//    and equal from the current index value
//  - otherwise loop for the other indices and determine if the values are alternating
// Return the total alternatinf groups
int numberOfAlternatingGroups(vector<int>& colors) {
    int tot = 0; int n = colors.size();

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (colors[n - 1] == colors[1] & colors[1] != colors[0]) {
                tot++;
            }

        } else if (i == n - 1) {
            if (colors[n - 2] == colors[0] & colors[i] != colors[0]) {
                tot++;
            }

        } else {

            if (colors[i - 1] == colors[i + 1] & colors[i] != colors[i - 1]) {
                tot++;
            }

        }

    }

    return tot;
}

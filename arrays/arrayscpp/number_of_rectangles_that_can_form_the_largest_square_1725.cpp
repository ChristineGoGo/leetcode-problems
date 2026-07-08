/*
    You are given an array rectangles where rectangles[i] = [li, wi] represents
    the ith rectangle of length li and width wi.

    You can cut the ith rectangle to form a square with a side length of k if both
    k <= li and k <= wi. For example, if you have a rectangle [4,6], you can cut it
    to get a square with a side length of at most 4.

    Let maxLen be the side length of the largest square you can obtain from any of the given rectangles.

    Return the number of rectangles that can make a square with a side length of maxLen.


    Example 1:

        Input: rectangles = [[5,8],[3,9],[5,12],[16,5]]
        Output: 3
        Explanation: The largest squares you can get from each rectangle are of lengths [5,3,5,5].
        The largest possible square is of length 5, and you can get it out of 3 rectangles.

    Example 2:

        Input: rectangles = [[2,3],[3,7],[4,3],[3,7]]
        Output: 3


    Constraints:

        1 <= rectangles.length <= 1000
        rectangles[i].length == 2
        1 <= li, wi <= 109
        li != wi
*/


// APPROACH: Create a variable to store the largest
// square side and set it to one.
// Create a vector to store all the sides
// Loop for each rectangle:
//      - pick the smallest side
//      - add the smallest side to the sides vector
//      - compare the smallest side to the largest square side
//      - set the largest variable to equal the smallest if it is bigger
// Return the largest square side
int countGoodRectangles(vector<vector<int>>& rectangles) {
    int largest = 1; int tot = 0;
    vector<int> sides;

    for (vector rectangle: rectangles) {
        int currLarg = min(rectangle[0], rectangle[1]);
        if (currLarg > largest) {
            largest = currLarg;
        }
        sides.push_back(currLarg);
    }

    for (int i: sides) {
        if (i == largest) tot++;
    }

    return tot;

}



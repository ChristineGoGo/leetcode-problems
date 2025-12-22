/*
    You are given an integer array coordinates, coordinates[i] = [x, y],
    where [x, y] represents the coordinate of a point. Check if these
    points make a straight line in the XY plane.

    Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
    Output: true

    Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
    Output: false

    Constraints:

    2 <= coordinates.length <= 1000
    coordinates[i].length == 2
    -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
    coordinates contains no duplicate point.

*/



// APPROACH: the gradient of a line m = (y - y1) / (x - x1)
// two points of a line have the same gradient
// the modified equation is: x2 - x1(y - y1) = y2 - y1 (x - x1)
// the equation must be true for all points of a straight line


bool checkStraightLine(vector<vector<int>>& coordinates) {
    int x1 = coordinates[1][0], x0 = coordinates[0][0];
    int y1 = coordinates[1][1], y0 = coordinates[0][1];

    for (int i = 2; i < coordinates.size(); i++) {
        int x2 = coordinates[i][0];
        int y2 = coordinates[i][1];
        if ((x2 - x1) * (y1 - y0) != (y2 - y1) * (x1 - x0)) return false;
    }

    return true;
}



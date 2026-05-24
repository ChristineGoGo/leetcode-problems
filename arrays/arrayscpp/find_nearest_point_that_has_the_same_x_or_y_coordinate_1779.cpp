/*
    You are given two integers, x and y, which represent your current location on a Cartesian grid: (x, y).
    You are also given an array points where each points[i] = [ai, bi] represents that a point exists at (ai, bi).
     A point is valid if it shares the same x-coordinate or the same y-coordinate as your location.

    Return the index (0-indexed) of the valid point with the smallest Manhattan distance from your current location.
    If there are multiple, return the valid point with the smallest index. If there are no valid points, return -1.

    The Manhattan distance between two points (x1, y1) and (x2, y2) is abs(x1 - x2) + abs(y1 - y2).


    Example 1:

        Input: x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
        Output: 2
        Explanation: Of all the points, only [3,1], [2,4] and [4,4] are valid. Of the valid points, [2,4] and [4,4]
        have the smallest Manhattan distance from your current location, with a distance of 1. [2,4] has the smallest index, so return 2.

    Example 2:

        Input: x = 3, y = 4, points = [[3,4]]
        Output: 0
        Explanation: The answer is allowed to be on the same location as your current location.

    Example 3:

        Input: x = 3, y = 4, points = [[2,3]]
        Output: -1
        Explanation: There are no valid points.
    

    Constraints:

        1 <= points.length <= 10*4
        points[i].length == 2
        1 <= x, y, ai, bi <= 10*4

*/
    // APPROACH:
    // Create function to find the manhattan distance
    // between two points
    // Create a map to store index of points and their manhattan distances
    // Create a vector to store the manhattan distances of all valid points
    // Loop for each point in points:
    //      - if point shares either x or y coordinates with given coordinate
    //              - calculate the manhattan distance
    //              - add manhattan distance as the value and point index as the key
    //              - add manhattan distance to a vector
    //      - if point doesnt share x or y coordinate make manhattan point 1000
    //         as the value for the map
    // Sort the manhattan distance in ascending order
    // Loop through the map and return the index of the point with the smallest
    // manhattan distance
int findManhattanDistance(int x, int y, vector<int> point) {
    return abs(point[0] - x) + abs(point[1] - y);
}

int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    map<int, int> indicesAndMdistances;
    vector<int> mDistances;
    int idx = 0;

    for (vector<int> point: points) {
        if (point[0] == x || point[1] == y) {
            indicesAndMdistances[idx] = findManhattanDistance(x, y, point);
            mDistances.push_back(findManhattanDistance(x, y, point));
        } else {
            indicesAndMdistances[idx] = 1000;
        }
        idx++;
    }


    if (mDistances.size() > 0) {
        sort(mDistances.begin(), mDistances.end());
        for (auto& v: indicesAndMdistances){
            if(v.second == mDistances[0]) return v.first;
        }
    }


    return -1;

}



// import java.util.Math;
/*
    Given an array of points on the X-Y plane points where points[i] = [xi, yi]
    ,return the area of the largest triangle that can be formed by any three different points. 
    Answers within 10-5 of the actual answer will be accepted.

    

    Example 1:


    Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
    Output: 2.00000
    Explanation: The five points are shown in the above figure. The red triangle is the largest.
    Example 2:

    Input: points = [[1,0],[0,0],[0,1]]
    Output: 0.50000
    

    Constraints:

    3 <= points.length <= 50
    -50 <= xi, yi <= 50
    All the given points are unique.
*/

/*
 * APPROACH: 
 * Use the Shoelace math formulae to find the area of the 
 * triangles. Create a function to only find the area.
 * Keep calculating the area until the max is found.
 */


public class largestTriangleArea_812 {
    public static double getArea(int[] a, int[] b, int[] c) {
        double area = ((a[0] * b[1]) + (b[0] * c[1] )+ (c[0] * a[1])) - ((a[1] * b[0]) + (b[1] * c[0]) + (c[1] * a[0]));
        return Math.abs(area)/ 2;
    }

    public static double largestTriangleArea(int[][] points) {
        double result = 0;
        int n = points.length;
        // loop through the points array
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if (result < getArea(points[i], points[j], points[k]) ) {
                        result = getArea(points[i], points[j], points[k]);
                    }
                }
            }
        }
        return result;
    }



    public static void main(String[] args) {
        int[][] test1 = {{4, 6}, {6, 5}, {3, 1}};
        int[] a = {4, 6};
        int[] b = {6, 5};
        int[] c = {3, 1};
        System.out.println(getArea(a, b, c));
        System.out.println(largestTriangleArea(test1));

    }
    
}

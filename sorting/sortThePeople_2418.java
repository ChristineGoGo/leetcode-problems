package sorting;
/*
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
 

Constraints:

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.
*/

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class sortThePeople_2418 {
    public String[] sortPeople(String[] names, int[] heights) {
        /*
         * APPROACH: Add the heights and names into a hashmap.
         * Sort the keys(height) of the map
         * Add the values of the sorted keys in an array
         * return the sorted array.
        */
        Map<Integer, String> people = new HashMap<>();
        String[] res = new String[names.length];

        for (int i = 0; i < heights.length;i++) {
            String currName = names[i];
            people.put(heights[i], currName);
        }


        Arrays.sort(heights);
        int start = 0;
        // System.out.println(Arrays.toString(heights));

        for (int i = heights.length - 1; i >= 0;i--) {
            // System.out.println(heights[i]);
            // System.out.println(people.get(heights[i]));
            res[start] = people.get(heights[i]);
            start++;
        }

        return res;
    }
    
}

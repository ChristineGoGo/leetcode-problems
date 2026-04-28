/*
    Given an array of integers arr, replace each element with its rank.

    The rank represents how large the element is. The rank has the following rules:

        - Rank is an integer starting from 1.
        - The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
        - Rank should be as small as possible.
    

    Example 1:

        Input: arr = [40,10,20,30]
        Output: [4,1,2,3]
        Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
    Example 2:

        Input: arr = [100,100,100]
        Output: [1,1,1]
        Explanation: Same elements share the same rank.
    Example 3:

        Input: arr = [37,12,28,9,100,56,80,5,12]
        Output: [5,3,4,2,8,6,7,1,3]
        

    Constraints:

        0 <= arr.length <= 10**5
        -10**9 <= arr[i] <= 10**9
*/

// APPROACH: Create an array to store the results
// Add all vector numbers into a set
// Store all the numbers in arr and their indices
// a hash map.
// Loop through the set(since it is sorted) to
// populate the results array with the numbers according
// to their rank
vector<int> arrayRankTransform(vector<int>& arr) {
    int n = arr.size();
    vector<int> results;
    set<int> orderedArr;
    map<int, int> indexMap;

    for(int i = 0; i < n; i++){
        orderedArr.insert(arr[i]);
    }
    int idx = 1;
    for(int num: orderedArr) {
        indexMap[num] = idx;
        idx++;
    }


    for (int num: arr) {
        results.push_back(indexMap[num]);
    }

    return results;

}


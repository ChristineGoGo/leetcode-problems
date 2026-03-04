/*
    Given an integer array sorted in non-decreasing order,
    there is exactly one integer in the array that occurs
    more than 25% of the time, return that integer.

    

    Example 1:

    Input: arr = [1,2,2,6,6,6,6,7,10]
    Output: 6
    Example 2:

    Input: arr = [1,1]
    Output: 1
    

    Constraints:

    1 <= arr.length <= 104
    0 <= arr[i] <= 105
*/
// Create a map to store the frequency for the items in arr
// Loop through the map, if the percent occurance(freq/total items) * 100
//  is greater than 25% return the item
int findSpecialInteger(vector<int>& arr) {
    int n = arr.size();
    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    int t = n / 4;
    for (auto vals: freq) {       
        if (vals.second > t) return vals.first;
    }

    return -1;
}



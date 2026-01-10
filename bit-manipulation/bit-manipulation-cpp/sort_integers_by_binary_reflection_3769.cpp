/*


    You are given an integer array nums.

    The binary reflection of a positive integer is defined as
    the number obtained by reversing the order of its binary digits
    (ignoring any leading zeros) and interpreting the resulting binary number as a decimal.

    Sort the array in ascending order based on the binary reflection of each element.
    If two different numbers have the same binary reflection, the smaller original
    number should appear first.

    Return the resulting sorted array.



    Example 1:

    Input: nums = [4,5,4]

    Output: [4,4,5]

    Explanation:

    Binary reflections are:

    4 -> (binary) 100 -> (reversed) 001 -> 1
    5 -> (binary) 101 -> (reversed) 101 -> 5
    4 -> (binary) 100 -> (reversed) 001 -> 1
    Sorting by the reflected values gives [4, 4, 5].
    Example 2:

    Input: nums = [3,6,5,8]

    Output: [8,3,6,5]

    Explanation:

    Binary reflections are:

    3 -> (binary) 11 -> (reversed) 11 -> 3
    6 -> (binary) 110 -> (reversed) 011 -> 3
    5 -> (binary) 101 -> (reversed) 101 -> 5
    8 -> (binary) 1000 -> (reversed) 0001 -> 1
    Sorting by the reflected values gives [8, 3, 6, 5].
    Note that 3 and 6 have the same reflection, so we arrange them in increasing order of original value.


    Constraints:

    1 <= nums.length <= 100
    1 <= nums[i] <= 109

*/

#include <iostream>
#include <map>

using namespace std;

int findBinInfl(int num) {
    int n = num;
    string b = "";

    while(n > 0) {
        string curr = to_string(n % 2);
        b += curr;
        n /= 2;
    }


    int dec = 0;

    for (int i = 0; i < b.length(); i++) {
        string s = "";
        s += b[i];
        int curr = stoi(s);

        dec *= 2;
        dec += curr;
    }

    return dec;
}


vector<int> sortByReflection(vector<int>& nums) {
    vector<int> res;
    vector<vector<int>> bInflections;
    set<int> infSet;
    stable_sort(nums.begin(), nums.end());

    for (int num: nums) {

        int curr = findBinaryInflection(num);
        // cout<< "the inflection is: " << curr << " \n";
        bInflections.push_back({num, curr});
        infSet.insert(curr);
    }

    for (int num: infSet) {
        // cout << "num is: " << num << " \n";
        for (vector<int> n: bInflections) {
            if (n[1] == num) {
                res.push_back(n[0]);
            }
        }
    }

    return res;

}


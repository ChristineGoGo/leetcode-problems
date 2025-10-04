/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
 
Constraints:
1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104 

All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.
 

Follow up: Could you find an O(nums1.length + nums2.length) solution?


*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;



vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // initialize the variables needed
        map<int, int> m;
        vector<int> res;
        int len2 = nums2.size() - 1;
        int len1  = nums1.size();

        // fill the map with num2 indexes
        for (int i = 0; i < nums2.size(); i++) {
            m[nums2[i]] = i;
        }

        // loop through nums1 to find the next greater elements
        for (int j = 0; j < len1 ; j++) {
            int num = nums1[j];
            int currIndex = m[num];

            cout << "currIndex: " << currIndex << "\n";

            while (currIndex != len2) {
                if (nums2[currIndex + 1]  > num) {
                    res.push_back(nums2[currIndex + 1]);
                    break;
                }
                currIndex++;
            }
            cout << "later current index" << currIndex << "\n";
            cout << "*********************************";
            if (currIndex == len2) {
                res.push_back(-1);
            }
            

        }
        return res;
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result =  nextGreaterElement(nums1, nums2);

    for (int num: result) {
        cout << num;
    }
}
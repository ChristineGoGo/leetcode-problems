/*
    Given a fixed-length integer array arr, duplicate each occurrence of zero, 
    shifting the remaining elements to the right.

    Note that elements beyond the length of the original array are not written. 
    Do the above modifications to the input array in place and do not return anything.

    

    Example 1:

    Input: arr = [1,0,2,3,0,4,5,0]
    Output: [1,0,0,2,3,0,0,4]
    Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
    Example 2:

    Input: arr = [1,2,3]
    Output: [1,2,3]
    Explanation: After calling your function, the input array is modified to: [1,2,3]
    

    Constraints:

    1 <= arr.length <= 104
    0 <= arr[i] <= 9
*/

#include <iostream>
using namespace std;
// APPROACH: Use two pointers to keep track of the indexes where there are zeros to
// duplicate and a new array to store the original numbers in arr
void duplicateZeros(vector<int>& arr) {
    int curr = 0;
    int toAddIndex = 0;
    int n = arr.size();

    vector<int> darr = arr;

    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }

    while (toAddIndex < n) {
        if (darr[curr] != 0 ) {
            arr[toAddIndex] = darr[curr];
            toAddIndex++;
        } else {
            toAddIndex += 2;
        }
        curr++;
    }

    for (int num: arr) {
        cout << num << " ";
    }
    
    
}



int main() {
    vector<int> nums = {1, 2, 3, 0, 0, 5, 0, 9};
    duplicateZeros(nums);

}






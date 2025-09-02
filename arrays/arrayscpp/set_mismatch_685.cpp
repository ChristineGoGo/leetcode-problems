/*
    You have a set of integers s, which originally contains all the numbers from 1 to n.
    Unfortunately, due to some error, one of the numbers in s got duplicated to another
    number in the set, which results in repetition of one number and loss of another number.

    You are given an integer array nums representing the data status of this set after the error.

    Find the number that occurs twice and the number that is missing and return them in the form 
    of an array.

    

    Example 1:

    Input: nums = [1,2,2,4]
    Output: [2,3]
    Example 2:

    Input: nums = [1,1]
    Output: [1,2]
    

    Constraints:

    2 <= nums.length <= 104
    1 <= nums[i] <= 104

*/
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    int doubled;
    int missing;
    bool found = false;

    map<int, int> tracker;
    set<int> s;
    vector<int> result;

    //sort the vector
    stable_sort(nums.begin(), nums.end());

    //find the doubled number with a map
    for(int i = 0; i < n; i++) {
        s.insert(nums[i]);
        

        if (tracker[nums[i]] == 0) {
            tracker[nums[i]] = 1;;
        } else {
            tracker[nums[i]] = tracker[nums[i]] + 1;
        }

        if (tracker[nums[i]] == 2) {
            doubled = nums[i];
        }

       
    }

    result.push_back(doubled);
    
    int j = 1;
    // find the missing number from the set
    for (int num : s) {
        if (num != j) {
            missing = j;
            break;
        }
        j++;
    }
    
    missing = !found ? j : missing;
    result.push_back(missing);

    // cout << "missing: " <<  missing << " doubled: " << doubled << " ";
    return result;

}

int main() {
    vector<int> nums = {3,2,3,4,6,5};
    vector <int> res = findErrorNums(nums);

    for (int num: res) {
        cout << num << " ";
    }
    

    return 0;
}

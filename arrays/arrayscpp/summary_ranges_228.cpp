/*
    You are given a sorted unique integer array nums.

    A range [a,b] is the set of all integers from a to b (inclusive).

    Return the smallest sorted list of ranges that cover all the numbers in the array exactly.
    That is, each element of nums is covered by exactly one of the ranges, and there is no integer
    x such that x is in one of the ranges but not in nums.

    Each range [a,b] in the list should be output as:

        - "a->b" if a != b
        - "a" if a == b


    Example 1:

        Input: nums = [0,1,2,4,5,7]
        Output: ["0->2","4->5","7"]
        Explanation: The ranges are:
            [0,2] --> "0->2"
            [4,5] --> "4->5"
            [7,7] --> "7"
    Example 2:

        Input: nums = [0,2,3,4,6,8,9]
        Output: ["0","2->4","6","8->9"]
        Explanation: The ranges are:
            [0,0] --> "0"
            [2,4] --> "2->4"
            [6,6] --> "6"
            [8,9] --> "8->9"
    

    Constraints:

        0 <= nums.length <= 20
        -2**31 <= nums[i] <= 2**31 - 1
        All the values of nums are unique.
        nums is sorted in ascending order.

*/
// APPROACH: Create vector to store the results
// Use pointer(j) to track right indices
// Loop from the starting index(i == 0) in nums until end of nums
//      - if nums[i] != left pointer(j),add nums[i] , "->", and nums[pointer]
//        to result as string
//      - else add nums[i] as string to the result array
//      set i == j
// return results vector

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;

    int n = nums.size();
    int j;

    for (int i = 0; i < n; i++) {
        j = i;
        while(j < n - 1 && nums[j + 1] == nums[j] + 1) {
            j++;
        }


        if (i == j ) {
            result.push_back(to_string(nums[i]));

        } else {
            result.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
        }
        i = j;
    }

    return result;

}


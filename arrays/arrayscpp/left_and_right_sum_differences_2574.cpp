/*
    You are given a 0-indexed integer array nums of size n.

    Define two arrays leftSum and rightSum where:

    leftSum[i] is the sum of elements to the left of the index
    i in the array nums. If there is no such element, leftSum[i] = 0.
    rightSum[i] is the sum of elements to the right of the index i in
    the array nums. If there is no such element, rightSum[i] = 0.
    Return an integer array answer of size n where answer[i] = 
    |leftSum[i] - rightSum[i]|.



    Example 1:

    Input: nums = [10,4,8,3]
    Output: [15,1,11,22]
    Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
    The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].

    Example 2:

    Input: nums = [1]
    Output: [0]
    Explanation: The array leftSum is [0] and the array rightSum is [0].
    The array answer is [|0 - 0|] = [0].


    Constraints:

    1 <= nums.length <= 1000
    1 <= nums[i] <= 10**5
*/



// APPROACH: Create vector to store the result, currLeft for left sum
// of current index and currRight for the right sum
// Find the total sum of the given arrray
// Loop for each index in the given array:
//  - find the left sum. Add up left sum for each index as currLeft
//  = nums[idx - 1] + currLeft
//  - find the right sum which is the totalSum - nums[idx]. Update after
// finding the right sum. Find the absolute difference of the left and
// the right sum and add it to the result
// return the result vector
vector<int> leftRightDifference(vector<int>& nums) {
    vector<int> ans;
    int currLeft = 0; int currRight = 0; int n = nums.size();

    // find the total sum
    for (int num: nums) {
        currRight += num;
    }

    for (int i = 0; i < n; i++) {
        // find left sum
        if (i > 0) currLeft += nums[i - 1];

        // find right sum
        currRight -= nums[i];

        ans.push_back(abs(currRight - currLeft));
    }

    return(ans);
}





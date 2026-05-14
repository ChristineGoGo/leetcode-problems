/*
    You are given an array nums of n integers and two integers k and x.

    The x-sum of an array is calculated by the following procedure:

        - Count the occurrences of all elements in the array.
        - Keep only the occurrences of the top x most frequent elements.
          If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
        - Calculate the sum of the resulting array.

    Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

    Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].


    Example 1:

        Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2

        Output: [6,10,12]

        Explanation:

            - For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
            - For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4.
            Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
            - For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.

    Example 2:

        Input: nums = [3,8,7,8,7,5], k = 2, x = 2

        Output: [11,15,15,15,12]

        Explanation:

        Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].


    Constraints:

        1 <= n == nums.length <= 50
        1 <= nums[i] <= 50
        1 <= x <= k <= nums.length

*/

// APPROACH: Use a hashmap to store the frequencies
// Create a vector to store the results
// Loop for each subarray containing k values
// Find the frequencies of the numbers
// Sort according to key value
// Find the sum to populate the answer vector
vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<int> ans;
    int xSum = 0;

    for (int i = 0; i <= n - k; i++) {
        // find frequencies of k numbers
        map<int, int> freq;
        for (int j = i; j < i + k; j++) {
            freq[nums[j]]++;
        }
        // store frequencies and numbers in vector pair to sort them
        vector<pair<int, int>> valFreq;
        for (auto v: freq){ 
            valFreq.emplace_back(v.second, v.first);
        }

        sort(valFreq.begin(), valFreq.end(), greater<pair<int,int>>());
        xSum = 0;
        for (int f = 0; f < x && f < valFreq.size(); f++) {
            xSum += valFreq[f].first * valFreq[f].second;
        }
        ans.push_back(xSum);
    }

    return ans;
}


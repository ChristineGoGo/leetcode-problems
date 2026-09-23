/*
    You are given an integer array nums.

    The digit range of an integer is defined as the difference between
    its largest digit and smallest digit.

    For example, the digit range of 5724 is 7 - 2 = 5.

    Return the sum of all integers in nums whose digit range is equal
    to the maximum digit range among all integers in the array.


    Example 1:

        Input: nums = [5724,111,350]

        Output: 6074

        Explanation:

        i	nums[i]	Largest	    Smallest	Digit Range
        0	5724	  7	          2	              5
        1	111	      1	          1	              0
        2	350       5	          0	              5
        The maximum digit range is 5. The integers with this
        digit range are 5724 and 350, so the answer is 5724 + 350 = 6074.

    Example 2:

        Input: nums = [90,900]

        Output: 990

        Explanation:

            i	nums[i]	Largest	Smallest	Digit Range
            0	90	        9	    0	         9
            1	900	        9	    0	         9

    The maximum digit range is 9. Both integers have this digit range, so the answer is 90 + 900 = 990.


    Constraints:

        1 <= nums.length <= 100
        10 <= nums[i] <= 10**5

*/

// Create function to find the largest and smallest
// number in each digit.Return the digits in a vector
// Find the maximum digit range
// Add all the digits with the maximum digit range
// into a vector
// Return the sum of all the numbers in the maximum digit range
// vector
vector<int> getMinMaxRange(int m) {
    int temp = m;
    int minNum = 1000; int maxNum = 0;
    vector<int> res(2, 0);
    while (temp > 0) {
        int curr = temp % 10;
        minNum = min(minNum, curr);
        maxNum = max(maxNum, curr);
        temp /= 10;
    }

    res[0] = minNum;
    res[1] = maxNum;
    return res;
}

int maxDigitRange(vector<int>& nums) {
    int r = 0; int n = nums.size();
    int maxDigitRangeNum = 0;
    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        vector<int> vect = getMinMaxRange(nums[i]);
        // cout << "the minimum number is: " << vect[0] << "\n";
        // cout << "the maximum number is: " << vect[1] << "\n";

        int digitRange = vect[1] - vect[0];

        freq[nums[i]] = digitRange;
        maxDigitRangeNum = max(digitRange, maxDigitRangeNum);
    }

    for (int i = 0; i < n; i++) {
        if (freq[nums[i]] == maxDigitRangeNum) {
            r += nums[i];
        }
    }

    return r;

}


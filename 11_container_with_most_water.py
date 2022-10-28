"""
    11. Container With Most Water
    Medium


    You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

    Find two lines that together with the x-axis form a container, such that the container contains the most water.

    Return the maximum amount of water a container can store.

    Notice that you may not slant the container.



    Example 1:

    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

    Example 2:

    Input: height = [1,1]
    Output: 1



    Constraints:

    n == height.length
    2 <= n <= 105
    0 <= height[i] <= 104


"""
class Solution:
    def maxArea(self, height):
        # absolute brute force
        # areas = []
        # max_area = 0
        # for i in range(len(height)):
        #     for j in range(i, len(height)):
        #         h = min(height[i], height[j])
        #         d = j - i
        #         a = h * d
        #         max_area = max(a, max_area)
        #         # areas.append(a)
        # return max_area

        # enhanced but same Time Complexity O(N2)
        # m = 0
        # if len(height) <= 2: m = min(height)
        # for i in range(len(height) - 1, 0, -1):
        #     for j in range(i - 1, -1, -1):
        #         a = min(height[i], height[j]) * (i - j)
        #         if a > m:
        #             m = a
        # return m

        # two pointer O(N) complexity
        # set pointer at the outermost indexes
        l, r = 0, len(height) - 1
        # set minimum height to 0
        m = 0

        # loop while the left index < right index
        while l < r:
            a = min(height[l], height[r]) * (r - l)
            print(a)
            if a > m: m = a
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1

        return m

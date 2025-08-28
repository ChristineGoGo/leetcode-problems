# Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
#
# Each element in the array represents your maximum jump length at that position.
#
# Your goal is to reach the last index in the minimum number of jumps.
#
# You can assume that you can always reach the last index.


def jump(nums):
    min_jump = 0
    left = right = 0
    while right < len(nums) - 1:
        farthest = 0
        for i in range(left, right + 1):
            farthest = max(nums[i] + i, farthest)
            # print(farthest)
        left = right + 1
        right = farthest
        min_jump += 1

    return min_jump


if __name__ == '__main__':
    n = [2, 3, 1, 1, 4]
    print(jump(n))


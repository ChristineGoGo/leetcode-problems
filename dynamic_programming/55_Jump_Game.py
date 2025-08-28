# You are given an integer array nums.
# You are initially positioned at the array's first index,
# and each element in the array represents your maximum jump length at that position.
# Return true if you can reach the last index, or false otherwise.


def canJump(nums) -> bool:
    reachable = 0
    length = len(nums)
    if length == 1:
        return True

    for i in range(0, length):
        if reachable < i:
            return False
        else:
            reachable = max(reachable, i + nums[i])

    return True


if __name__ == '__main__':
    print(canJump([2, 3, 1, 1, 4]))



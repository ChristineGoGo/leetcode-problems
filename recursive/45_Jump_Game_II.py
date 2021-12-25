import sys


def minJumps(nums, start, end):
    if end == start:
        return 0

    if nums[start] == 0:
        return sys.maxsize

    min_jumps = sys.maxsize

    for i in range(start + 1, end + 1):
        if i < nums[i] + start + 1:
            jumps = minJumps(nums, i, end)
            print(f"jumps: {jumps}, i:{i}, nums[i]: {nums[i]}")
            if jumps != sys.maxsize and jumps + 1 < min_jumps:
                min_jumps = jumps + 1

    return min_jumps


if __name__ == '__main__':
    nums = [1, 3, 6, 3, 2, 3, 6, 8, 9, 5]
    end = len(nums) - 1
    print(minJumps(nums, 0, end))

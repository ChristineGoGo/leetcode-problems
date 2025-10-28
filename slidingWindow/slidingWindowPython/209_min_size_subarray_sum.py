import sys


def minSubArrayLen(target, nums):
    min_subarray = sys.maxsize
    start, end = 0, 1
    while end <= len(nums):
        current_sum = sum(nums[start:end])
        if current_sum >= target:
            min_subarray = min(min_subarray, end - start)
            print(min_subarray, current_sum)
            if min_subarray == 1:
                return 1
            current_sum -= nums[start]
            start += 1
        else:
            end += 1

    return min_subarray


if __name__ == '__main__':
    nums = [2, 3, 2, 2, 4, 3]
    target = 6
    print(minSubArrayLen(target, nums))

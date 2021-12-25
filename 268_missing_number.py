def missingNumber(nums):
    n = len(nums)
    nums_set = set(nums)
    missing = 0
    for i in range(1, n + 1):
        if i not in nums_set:
            return i
    return missing


if __name__ == '__main__':
    assert missingNumber([3, 0, 1]) == 2
    assert missingNumber([0, 1]) == 2
    assert missingNumber([9, 6, 4, 2, 3, 5, 7, 0, 1]) == 8
    assert missingNumber([0]) == 1
    assert missingNumber([1]) == 0



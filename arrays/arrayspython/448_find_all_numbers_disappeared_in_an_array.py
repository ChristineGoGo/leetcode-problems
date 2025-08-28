"""
    Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
"""
def findDisappearedNumbers(nums):
    import numpy as np
    arr1 = np.array(nums)
    arr2 = np.array(list(range(1, len(nums) + 1)))
    return list(np.setdiff1d(arr2, arr1))

print(f'findDisappearedNumbers(nums = [4,3,2,7,8,2,3,1]): {findDisappearedNumbers(nums = [4,3,2,7,8,2,3,1])}') #[5, 6]
print(f'findDisappearedNumbers(nums = [1,1]): {findDisappearedNumbers(nums = [1,1])}') #[2]
print(f'findDisappearedNumbers(nums = [1]): {findDisappearedNumbers(nums = [1])}') #[]


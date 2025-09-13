"""
    Given an integer array nums, return true if any value appears at least twice in the array, 
    and return false if every element is distinct.
"""
def containsDuplicate(nums):
    f = {}
    for number in nums:
        if number not in f : 
            f[number] = 1
        else:
            f[number] += 1
    
    values = f.values()
    for value in values:
        if value >= 2: return True
    
    return False

print(f'containsDuplicate(nums = [1,2,3,1]): {containsDuplicate(nums = [1,2,3,1])}') #True
print(f'containsDuplicate(nums = [1,2,3,4]): {containsDuplicate(nums = [1,2,3,4])}') #False
print(f'containsDuplicate(nums = [1,1,1,3,3,4,3,2,4,2]): {containsDuplicate(nums = [1,1,1,3,3,4,3,2,4,2])}') #True
print(f'containsDuplicate(nums = [1, 1]): {containsDuplicate(nums = [1,1])}') # True
print(f'containsDuplicate(nums = [1]): {containsDuplicate(nums = [1])}') # False

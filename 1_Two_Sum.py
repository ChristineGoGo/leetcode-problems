def twoSum(nums, target):
    dicts = {}
    for i in range(len(nums)):
        x = target - nums[i]
        if x in dicts:
            return dicts[x], i
        else:
            dicts[nums[i]] = i

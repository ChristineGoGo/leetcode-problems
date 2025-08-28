"""
    Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

    Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

 """
# #  APPROACH 1 BRUTE FORCE
# def findShortestSubArray(nums):
    # from collections import Counter

    # nums_frequency = Counter(nums)
    # nums_degree = nums_frequency.most_common(1)[0][1]

    # res = []

    # for j in range(len(nums), 0, -1):
    #     for i in range(j):
    #         if (Counter(nums[i:j]).most_common(1)[0][1] == nums_degree):
    #             res.append(nums[i:j])
    # return len(res[-1])

#  APPROACH 2 KINDA DYNAMIC PROGREAMMING BUT TIME LIMIT EXCEEDED
# def findShortestSubArray(nums):
#     from collections import Counter

#     n = len(nums)
#     nums_freq = Counter(nums)
#     nums_degree = max(nums_freq.values())
#     if nums_degree == 1: return 1
#     shortest = n

#     for i in range(n):
#         if nums_freq[nums[i]] == nums_degree:
#             for j in range(n - 1, i, -1):
#                 if nums[j] == nums[i] and (max(Counter(nums[i:j+1]).values()) == nums_degree):
#                     current_shortest = (j - i) + 1
#                     if shortest > current_shortest:
#                         shortest = current_shortest
#     return shortest

#  APPROACH 3 USING DICTIONARIES TO SAVE TIME COMPLEXITY
def findShortestSubArray(nums):
    from collections import Counter

    n = len(nums)
    nums_freq = Counter(nums)
    nums_degree = max(nums_freq.values())

    if nums_degree == 1: return 1

    shortest = n
    l, r = {}, {}

    for i, x in enumerate(nums):
        if x not in l: l[x] = i
        if x in l and nums_freq[x] > 1: r[x] = i

    for k, v in nums_freq.items():
        if v == nums_degree:
            current_shortest = r[k] - l[k] + 1
            shortest = min(shortest, current_shortest)


    return shortest







print(f'findShortestSubArray(nums = [1,2,2,3,1]): {findShortestSubArray(nums = [1,2,2,3,1])}') #2
print(f'findShortestSubArray(nums = [1,2,2,3,1,4,2]): {findShortestSubArray(nums = [1,2,2,3,1,4,2])}') #6
print(f'findShortestSubArray(nums = [1]): {findShortestSubArray(nums = [1])}') #1
print(f'findShortestSubArray(nums = [1, 2]): {findShortestSubArray(nums = [1, 2])}') #1
print(f'findShortestSubArray(nums = [1, 2, 3]): {findShortestSubArray(nums = [1, 2, 3])}') #1
print(f'findShortestSubArray(nums = [1, 2, 3, 2]): {findShortestSubArray(nums = [1, 2, 3, 2])}') #3
print(f'findShortestSubArray(nums = [1, 2, 2, 3]): {findShortestSubArray(nums = [1, 2, 2, 3])}') #2



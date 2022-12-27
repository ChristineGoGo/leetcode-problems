"""
    Given an integer array nums which is sorted in ascending order and all of its elements
    are unique and given also an integer k, return the kth missing number starting from the
    leftmost number of the array.

    Example 1:
        input: nums = [4, 7, 9, 10], k = 1
        output: 5

        explanation: The first missing number is 5.

    Example 2:
        input: nums = [4, 7, 9, 10] k = 3
        output: 8

        explanation: The missing numbers are [5, 6, 8, ...]
        hence the third missing number is 8

    Example 3:
    input: nums = [1, 2, 4], k = 3
    output: 6

    explanation: The missing numbers are [3, 5, 6, 7, ...]
    hence the third missing number is 6

    Constraints:
        1 <= nums.length <= 5 * 10^4
        1 <= nums[i] <= 10^7
        nums is sorted in ascending order, and all the elements
        are unique
        1 <= k<= 10^8

"""
def missingElement(nums, k):
    n = len(nums)

    # kth missing is greater than last index of the array
    if k > missing(n - 1, nums):
        return nums[n - 1] + k - missing(n - 1 , nums)

    # LINEAR SEARCH(O(N)) find the index of the first kth missing element < k
    # while missing(idx, nums) < k:
    #     idx = 1
    #     idx += 1

    # Binary Search O(LogN)
    l, r = 0, n - 1
    while l != r:
        idx = l + (r - l) // 2
        if missing(idx, nums) < k:
            l += 1
        else:
            r = idx

    # kth missing is greater than nums[idx - 1] and less than
    # nums[idx] for Linear Search
    # return nums[idx - 1] + k - missing(idx - 1, nums)

    # kth missing is greater than nums[l - 1] and less than
    # nums[l] for binary search
    return nums[l - 1] + k - missing(l - 1, nums)





def missing(x, nums):
    """
    Args:
        x (integer): the current index
        nums (array): the array used with index to identify missing elements

    Returns:
        integer : the number of missing elements from the leftmost index upto current
        index(x)
    """
    curr_val = nums[x]
    prev_val = nums[0]

    return curr_val - prev_val - x

print(missingElement(nums=[579, 1310], k = 2))

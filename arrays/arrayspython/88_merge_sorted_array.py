"""
    You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
    and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
    Merge nums1 and nums2 into a single array sorted in non-decreasing order.

    The final sorted array should not be returned by the function, but instead be stored inside the
    array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote
    the elements that should be merged, and the last n elements are set to 0 and should be ignored.
    nums2 has a length of n.
"""
# ------------- SOLUTION 1
# def merge(nums1, m, nums2, n):
    # if n == 0: return nums1

    # wr, n1, n2 = 0, 0, 0
    # nums1_copy = nums1[0: m]

    # while wr < n + m:
    #     # print(f'n1: {n1}, n2:{n2}, wr: {wr}')
    #     if (n1 < m and n2 < n and nums1_copy[n1] <= nums2[n2]) or n2 >= n:
    #         nums1[wr] = nums1_copy[n1]
    #         n1 += 1
    #     else:
    #         nums1[wr] = nums2[n2]
    #         n2 += 1

    #     wr += 1

# ------------- SOLUTION 2
def merge(nums1, m, nums2, n):
    if n == 0: return nums1

    n1 = m - 1
    n2 = n - 1
    end = m + n - 1

    while end >= 0:
        if (n2 >= 0  and nums2[n2] > nums1[n1] or n1 < 0):
            nums1[end] = nums2[n2]
            n2 -= 1
        else:
            nums1[end] = nums1[n1]
            n1 -= 1
        end -= 1

    return nums1

print(f'merge(nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3: {merge(nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3)} ') #[1, 2, 2, 3, 5, 6]
print(f'merge(nums1 = [1], m = 1, nums2 = [], n = 0) : {merge(nums1 = [1], m = 1, nums2 = [], n = 0)} ') #[1]
print(f'merge(nums1 = [0], m = 0, nums2 = [1], n = 1) : {merge(nums1 = [0], m = 0, nums2 = [1], n = 1)} ') #[1]
print(f'merge(nums1 = [2, 0], m = 1, nums2 = [1], n = 1) : {merge(nums1 = [2, 0], m = 1, nums2 = [1], n = 1)} ') #[1, 2]




"""Given an array, rotate the array to the right by k steps, 
    where k is non-negative.
"""


class Solution:
    def reverse(self,nums, start, end):
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start, end = start + 1, end - 1
        return nums
    
    def rotate(self, nums, k):
        """
        Do not return anything, modify nums in-place instead.
        """
        ## method 1
        # for i in range(k):
        #     temp = nums.pop()
        #     nums.insert(0, temp)
        
        ## method2
        # nums = nums[k+1:] + nums[:k+1]
        n = len(nums) - 1
        # do k %  len(nums) for situations where k >= the length of the array
        k = k % len(nums)
        
        
        self.reverse(nums, 0, n)
        self.reverse(nums, 0, k-1)
        self.reverse(nums, k, n)
     
        return nums
        
if __name__ == '__main__':
    s = Solution()
    assert (s.rotate([1,2,3],4) == [3,1,2])
    assert (s.rotate([1,2],2) == [1,2])
    assert (s.rotate([1,2],3) == [2,1,1])

    
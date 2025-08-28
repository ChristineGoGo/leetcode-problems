""" Given an array of integers nums which is sorted in ascending order, 
 and an integer target, write a function to search target in nums. 
 If target exists, then return its index. Otherwise, return -1.
 You must write an algorithm with O(log n) runtime complexity."""


class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        start, end = 0, len(nums) - 1
        index = -1
        
        if target not in nums:
            return index
        elif nums[-1] == target:
            index = len(nums) -1
            return index
        
 
        while start < end:
            middle = (start + end) // 2
            # print(middle)
            if nums[middle] == target:
                index = middle
                return index
            elif nums[middle] < target:
                start = middle
                # print("the start has changed")
                # print(start)
            else:
                end = middle 
                # print("the end has changed")
                # print(end)
            
            # start, end = start + 1, end - 1              
       
        return index
            
            
            

if __name__ == '__main__':
    s = Solution()
    print(s.search([-1,0,3,5,9,12], 12))

        
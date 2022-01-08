"""Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

"""

class Solution:
    def moveZeroes(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        
        ## solution 1
        # new_nums  = []
        # for i in range(len(nums)):
        #     # print(i)
        #     if nums[i] > 0:
        #         new_nums.append(nums[i])
        
        # zeros = len(nums) -len(new_nums)
        # print(zeros)
        
        # for i in range(zeros):
        #     new_nums.append(0)
        
        ## solution 2
        # zeros = nums.count(0)
        # for i in range(zeros):
        #     nums.append(0)
        #     nums.remove(0)
            
        ## solution 3 two pointer
        
        n = len(nums)
        right = left = 0
        
        for i in range(n):
            # print(f'right = {right} left= {left}')
            
            if nums[right] != 0:
                if nums[left] == 0:
                    temp = nums[left]
                    nums[left] = nums[right]
                    nums[right] = temp
                    left += 1
                else:
                    left += 1
            print(nums)
            right += 1
            
            print("Left: {left} {right}".format(left=left,right=right))
        

        
        return nums

if __name__ == '__main__':
    s = Solution()
    assert s.moveZeroes([0,1,0,3,0]) == [1,3,0,0,0]
    assert s.moveZeroes([0,]) == [0]
    assert s.moveZeroes([1,0,1]) == [1,1,0], s.moveZeroes([1,0,1])
    assert s.moveZeroes([0,0,1]) == [1,0,0]
    assert (s.moveZeroes([1,0,0,1]) == [1,1,0,0])

    # print(s.moveZeroes([0,1,0,3,12]))

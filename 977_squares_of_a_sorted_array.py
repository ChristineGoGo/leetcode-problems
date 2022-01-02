""" Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order."""

class Solution:
    def sortedSquares(self, nums):
        left, right = 0, len(nums) - 1
        # create new array to hold the squared values in ascending order
        squares = [0] * len(nums)
        squares_index = len(squares) - 1
        
        # loop through and compare values to find the greater value
        while left <= right:
            # print(left, right)
            # print(squares_index)
            if left == right:
                squares[squares_index] = abs(nums[left]) ** 2
                # print(squares)
                return squares
            elif abs(nums[right])  >= abs(nums[left]):
                # squares[right] = squares[left] ** 2)
                squares[squares_index] = abs(nums[right]) ** 2
                right -= 1
                # print(squares)
            else:
                squares[squares_index] = abs(nums[left]) ** 2
                left += 1
                # print(squares)
            squares_index -= 1

if __name__ == '__main__':
    # nums = [-4,-1,0,3,10]
    # nums = [2,2,3,5]
    s = Solution()
    assert (s.sortedSquares([-4,-1,0,3,10]) == [0,1,9,16,100])
    assert (s.sortedSquares([-7,-3,2,3,11]) == [4,9,9,49,121])
    assert (s.sortedSquares([-5,-3,-2,-1]) == [1,4,9,25])
    assert (s.sortedSquares([-4]) == [16])
    assert (s.sortedSquares([-4,-7]) == [16,49])
    assert (s.sortedSquares([-4,-7]) == [16,49])
    assert (s.sortedSquares([-4,-7,-10]) == [16,49,100])

    # print(assert (s.sortedSquares([-4,-1,0,3,10])))
    
    
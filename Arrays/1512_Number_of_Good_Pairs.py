"""Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j."""

class Solution:
    def numIdenticalPairs(self, nums):
        # Brutte Force
        # pairs = 0
        # for i in range(len(nums)-1,0, -1):
        #     for j in range(i):
        #         if nums[i] == nums[j]:
        #             pairs += 1
        # return pairs
        
        # Optimized solution
        # find the frequency of each number in nums and 
        # insert into an array
        s = [0] * (max(nums)+5)
        pairs = 0
        
        
        for i in nums:
            s[i] += 1
        
        print(nums, s)
        
        # loop through the frequency array to find combinations available if
        # the total count of each number is greater than 1
        for i in s:
            if i > 1:
                pairs += (i * (i-1))/2
            
        return pairs
        
        
if __name__ == '__main__':
    s = Solution()
    print(s.numIdenticalPairs([1,1,1,1]))
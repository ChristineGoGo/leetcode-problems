class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        temp = []
        return self.helper(nums, temp, results = [])

    def helper(self,nums, temp, results):
        if not nums:
            results.append(temp[:])
        for i in range(len(nums)):
            temp.append(nums[i])
            newNums = nums[:i] + nums[i+1:]
            self.helper(newNums, temp, results)
            temp.pop()

        return results


# test1
print(f"permute([1, 2, 3]): {permute([1, 2, 3])} ") # [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
# test2
print(f"permute([0, 1]): {permute([0, 1])} ") # [[1, 0], [0, 1]]
# test3
print(f"permute([1]): {permute([1])} ") # [[1]]
# test4
print(f"permute([1, 2, 3, 4, 5, 6]): {permute([1, 2, 3, 4, 5, 6])} ")
# [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]



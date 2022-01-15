"""Write a function that reverses a string. 
The input string is given as an array of characters s.

You must do this by modifying the input array 
in-place with O(1) extra memory."""



class Solution:
    def reverseString(self, s):
        """
        Do not return anything, modify s in-place instead.
        """
        start, end = 0, len(s)-1
        while start < end:
            s[start], s[end] = s[end], s[start]
            start, end = start + 1, end - 1

        return s

if __name__ == '__main__':
    answer = Solution()
    print(answer.reverseString(["h","e","l","l","o"]))
    # assert answer.reverseString(["h","e","l","l","o"]) == ["o","l","l","e","h"]

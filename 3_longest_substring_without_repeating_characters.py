"""
    Given a string s, find the length of the longest
    substring without repeating characters.

"""
from collections import Counter
#-------------------- BRUTE FORCE TIME LIMIT EXCEEDED
# def lengthOfLongestSubstring(s):
#     n = len(s)
#     longest = 0
#     for i in range(n):
#         for j in range(i, n + 1):
#             curr = s[i:j]
#             if checkRepeating(curr):
#                 longest = max(longest, len(curr))
#     return longest
#--------------------- SLIDING WINDOW W HELPER FUNCTION
# def lengthOfLongestSubstring(s):
#     b, e, n = 0, 0, len(s)
#     longest = 0

#     while e < n:
#         curr = s[b:e + 1]
#         if checkRepeating(curr):
#             e += 1
#         else:
#             curr_l = e - b
#             longest = max(longest, (curr_l))
#             while b <= e:
#                 if not checkRepeating(curr):
#                     b += 1
#                     curr = curr[b:e + 1]
#                 else:
#                     break

#     return longest
# def checkRepeating(s):
#     d = {}
#     for i in range(len(s)):
#         if s[i] in d:
#             d[s[i]] += 1
#         else:
#             d[s[i]] = 1
#         if d[s[i]] > 1: return False
#     return True
#---------------------  SLIDING WINDOW WO HELPER FUNCTION
def lengthOfLongestSubstring(s):
    begin, end, n = 0, 0, len(s)
    characters = Counter()
    longest = 0

    while end < n:
        e = s[end]
        characters[e] += 1

        while characters[e] > 1:
            b = s[begin]
            characters[b] -= 1
            begin += 1

        longest = max(longest, (end - begin) + 1)
        end += 1
    return longest

# tests
print(f"lengthOfLongestSubstring('abcabcbb'): {lengthOfLongestSubstring('abcabcbb')} ") #3
print(f"lengthOfLongestSubstring('bbbbb'): {lengthOfLongestSubstring('bbbbb')} ") #1
print(f"lengthOfLongestSubstring('pwwkew'): {lengthOfLongestSubstring('pwwkew')} ") #3
print(f"lengthOfLongestSubstring('dvdfd'): {lengthOfLongestSubstring('dvdfd')} ") #3

# given a string s, return the length of  the longest substring that contains at most two distinct characters
import sys


def lengthOfLongestSubstringTwoDistinct(s):
    start, end = 0, 0
    chars = [0] * 128
    max_length = -sys.maxsize
    distinct = 0

    while end < len(s):
        c = s[end]
        if chars[ord(c)] == 0:
            distinct += 1
        chars[ord(c)] += 1

        if distinct > 2:
            left = s[start]
            while chars[left] > 1:
                chars[left] -= 1
            start += 1

        max_length = max(max_length, start - end + 1)



if __name__ == '__main__':
    s = "eceba"
    lengthOfLongestSubstringTwoDistinct(s)

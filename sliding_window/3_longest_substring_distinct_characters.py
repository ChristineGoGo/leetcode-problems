import sys


def lengthOfLongestSubstring(s: str) -> int:
    chars = [0] * 128
    start, end = 0, 0
    max_int = -sys.maxsize

    while end < len(s):
        e = s[end]
        chars[ord(e)] += 1

        while chars[ord(e)] > 1:
            t = s[start]
            chars[ord(t)] -= 1
            start += 1

        max_int = max(max_int, end-start+1)

        end += 1

    if max_int > -sys.maxsize:
        return max_int
    else:
        return 0


if __name__ == '__main__':
    s = "   "
    print(lengthOfLongestSubstring(s))

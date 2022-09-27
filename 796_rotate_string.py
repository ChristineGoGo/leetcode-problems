"""
    Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

    A shift on s consists of moving the leftmost character of s to the rightmost position.

    For example, if s = "abcde", then it will be "bcdea" after one shift.
"""
def rotateString(s, goal):
    curr = ""
    i = 0
    while i < len(s):
        curr = s[i + 1:] + s[0:i + 1]
        if curr == goal: return True
        i += 1
    return False


print(f'{rotateString(s = "abcde", goal = "cdeab")} ') #True
print(f'{rotateString(s = "abcde", goal = "abced")} ') #False
print(f'{rotateString(s = "a", goal = "a")} ') #True
print(f'{rotateString(s = "a", goal = "b")} ') #False

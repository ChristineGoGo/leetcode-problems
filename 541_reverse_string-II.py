"""
    Given a string s and an integer k, reverse the first k characters
    for every 2k characters counting from the start of the string.

    If there are fewer than k characters left, reverse all of them.
    If there are less than 2k but greater than or equal to k characters,
    then reverse the first k characters and leave the other as original.
"""
def reverseStr(self, s: str, k: int) -> str:
    res = list(s)

    for i in range(0, len(s), (2 * k)):
        start = i
        end = len(s) - 1 if i + k  > len(s) else i + (k - 1)
        while start < end:
            temp = res[start]
            res[start] = res[end]
            res[end] = temp
            start += 1
            end -= 1

    return "".join(res)

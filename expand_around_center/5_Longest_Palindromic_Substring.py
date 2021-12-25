def expandAroundCenter(s, left, right):
    left, right = 0, len(s)
    len1 =
    while left > 0 and right < len(s) and s[left] == s[right]:
        left += 1
        right -= 1
    return


if __name__ == '__main__':
    s = "cbbd"
    print(expandAroundCenter(s, left, right))

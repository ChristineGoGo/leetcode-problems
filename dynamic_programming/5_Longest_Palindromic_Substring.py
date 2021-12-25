def longestPalindromicSubstring(s):
    if s == "":
        return s
    dp = [[0 for i in range(len(s))] for j in range(len(s))]
    longest = ""
    for i in range(len(s)):
        for j in range(i + 1):
            if i == j:
                dp[i][j] = True
            elif i == j + 1:
                dp[i][j] = (s[i] == s[j])
            else:
                dp[i][j] = (s[i] == s[j] and dp[i - 1][j + 1])
            if dp[i][j] and (i - j + 1) > len(longest):
                longest = s[j: i + 1]
    return longest

if __name__ == '__main__':
    assert ("babad") == "bab"
    print(longestPalindromicSubstring("cbbd"))



#-------------  brute force - time limit exceeded
# def longestPalindrome(s):
#     n = len(s)
#     res = ""

#     for i in range(n):
#         for j in range(i, n + 1):
#             if self.isPalindrome(s[i:j]):
#                 if len(res) < (j - i):
#                     res = s[i:j]


#     return res

def isPalindrome(s):
    n_s = ""
    for i in range(len(s) -  1, -1, -1):
        n_s += s[i]
    return n_s == s
#------------------- two pointers
# class Solution:
#     res = ""
#     def longestPalindrome(self, s):
#         n = len(s)
#         def checkPalindrome(b, e):
#             while ((b >= 0 and e < n) and (s[b] == s[e])):
#                 curr_l = (e - b) + 1
#                 if curr_l > len(self.res):
#                     self.res = s[b: e + 1]
#                 b -= 1
#                 e += 1
#         for i in range(n):
#             checkPalindrome(i, i)
#             checkPalindrome(i, i + 1)

#         return self.res

#------------------- dynamic programming
class Solution:
    res = ""
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        # set up the dynamic programming table
        dp = [[0] * (n) for i in range(n)]
        for i in range(n):
            dp[i][i] = True

        # populate the rest of the table starting w
        # last index
        for i in range(n - 1, -1, -1):
            for j in range(i, n, 1):
                # two conditions of a palindromic substring:
                #   - outer characters are equal and inner word is a
                #     palindrome
                # inner word is a palindrome if dp[i + 1][j - 1]
                # is True or if it has one character
                if s[i] == s[j]:
                    if (j - i) == 1 or j == i or dp[i + 1][j -1]:
                        dp[i][j] = True
                        if len(self.res) < (j - i) + 1:
                            self.res = s[i:j +1]
                else:
                    dp[i][j] = False

        return self.res


# s = """
#     civilwartestingwhetherthatnaptionoranynartionsoconceivedand
#     sodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwar
#     Wehavecometodedicpateaportionofthatfieldasafinalrestingplacefor
#     thosewhoheregavetheirlivesthatthatnationmightliveItisaltogethe
#     rfangandproperthatweshoulddothisButinalargersensewecannotdedica
#     tewecannotconsecratewecannothallowthisgroundThebravelmenlivingand
#     deadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddor
#     detractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebut
#     itcanneverforgetwhattheydidhereItisforusthelivingrathertobededicated
#     heretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadva
#     ncedItisratherforustobeherededicatedtothegreattdafskremainingbeforeu
#     sthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhich
#     theygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthes
#     edeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirth
#     offreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth
# """
# print(f"longestPalindrome(s): {longestPalindrome(s)} ") #ranynar

s = "babad"
test = Solution()
print(f"longestPalindrome(s): {test.longestPalindrome(s)} ") #aba
# s = "abba"
# test = Solution()
# print(f"longestPalindrome(s): {test.longestPalindrome(s)} ") #abba


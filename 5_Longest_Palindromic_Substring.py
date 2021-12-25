# Brute Force
def longest_substring(s):
    def isPalindrome(s):
        start, end = 0, len(s) - 1
        while start < end:
            while start < end and not s[start].isalnum():
                start += 1
            while start < end and not s[end].isalnum():
                end -= 1
            if s[start].lower() != s[end].lower():
                return False

            start += 1
            end -= 1
        return True

    common_subs = {}
    for i in range(0, len(s)):
        for j in range(1, len(s)+1):
            if isPalindrome(s[i:j]):
                common_subs[s[i:j]] = len(s[i:j])
    print(common_subs)
    return max(common_subs, key=common_subs.get)


if __name__ == '__main__':
    sample_string = 'aaabbaa'
    print(longest_substring(sample_string))

def isPalindrome(s):
    s = "".join([x for x in list(s) if x.isalnum()]).replace(" ", "").lower()
    palindrome = True
    if 0 <= len(s) <= 1:
        palindrome = True
        return palindrome
    elif len(s) < 3:
        if s.count(s[1]) != len(s) or s[0] != s[-1]:
            palindrome = False
            return palindrome
    else:
        for i in range(0, len(s)//2):
            if s[i] != s[-1-i]:
                palindrome = False

    return palindrome


if __name__ == '__main__':
    sample_string = "A ba"
    print(isPalindrome(sample_string))

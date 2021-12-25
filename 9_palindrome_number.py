def isPalindrome(x):
    palindrome = True
    string_x = str(x)
    start, end = 0, len(string_x) - 1
    while start < end:
        if string_x[start] != string_x[end]:
            palindrome = False
        start += 1
        end -= 1

    return palindrome


if __name__ == '__main__':
    assert(isPalindrome(121) is True)
    assert(isPalindrome(-121) is False)
    assert(isPalindrome(1221) is True)
    assert(isPalindrome(-1221) is False)

def reverse(x):
    MIN_NUM = -2147483648
    MAX_NUM = 2147483648
    res = 0
    while x:
        digit = int(math.fmod(-x, 10))
        x = int(x / 10)
        # check to make sure that the number does not overflow
        if (res > MAX_NUM // 10 or
                res == MAX_NUM // 10 and digit >= MAX_NUM % 10):
            return 0


if __name__ == '__main__':
    assert (reverse(123) == 321)
    assert (reverse(-123) == -321)
    assert (reverse(120) == 21)
    assert (reverse(0) == 0)

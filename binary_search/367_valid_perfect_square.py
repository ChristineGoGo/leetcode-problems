"""
    Given a positive integer num, write a function which returns True if num is a perfect square else False.

    Follow up: Do not use any built-in library function such as sqrt
"""
import math
def isPerfectSquare(num):
    mid = math.ceil(num / 2)

    for number in range(mid + 1):
        if number * number == num: return True
        if number * number > num: return False


print(f'isPerfectSquare(16): {isPerfectSquare(16)}') #True
print(f'isPerfectSquare(14): {isPerfectSquare(14)}') #False
print(f'isPerfectSquare(1): {isPerfectSquare(1)}') #True

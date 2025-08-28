"""
    Given two binary strings a and b, return their sum as a binary string.
"""
def toDecimal(b):
        d = 0
        p = len(b) - 1
        for item in b:
            d += (int(item) * pow(2, p))
            p -= 1
        return d

def addBinary(a, b):
    res = toDecimal(a) + toDecimal(b)
    return f"{res:b}"

print(f'addBinary("1010", "1011"): {addBinary("1010", "1011")}') #10101

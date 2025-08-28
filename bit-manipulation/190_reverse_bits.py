"""
    Reverse bits of a given 32 bits unsigned integer.

    Note:

    Note that in some languages, such as Java, there is
    no unsigned integer type. In this case, both input
    and output will be given as a signed integer type.
    They should not affect your implementation, as the
    integer's internal binary representation is the same,
    whether it is signed or unsigned.
    In Java, the compiler represents the signed integers
    using 2's complement notation. Therefore, in Example 2 above,
    the input represents the signed integer -3 and the output
    represents the signed integer -1073741825.

 """
def toBinary(n):
    q = n
    binary = []

    while q > 0:
        r = q % 2
        q = int(q / 2)

        print(f'q:{q}, r: {r}')
        binary.insert(0, str(r))
    print(binary)
    # res = [str(i) for i in binary]
    return "".join(binary)

def toDecimal(b):
    total = 0
    i = len(b) - 1
    for item in b:
        curr = int(item) * (2 ** i)
        total += curr
        i -= 1
    return total

def reverseBits(n):
    b = f"{n:b} "
    pad =  32 - n.bit_length()
    p = list(b.zfill(pad + len(b)))


    start, end = 0, len(p) - 1
    while start < end:
        temp = p[start]
        p[start] = p[end]
        p[end] = temp
        start += 1
        end -= 1
    return toDecimal(p[1:])

# print(f'toDecimal("1011"): {toDecimal("1011")}') #11
# print(f'toBinary(43261596): {toBinary(43261596)}') #00000010100101000001111010011100

print(f'reverseBits(11):{reverseBits(11)}') #1101 or 13
print(f'reverseBits(43261596): {reverseBits(43261596)}') #964176192
print(f'reverseBits(4294967293): {reverseBits(4294967293)}') #3221225471


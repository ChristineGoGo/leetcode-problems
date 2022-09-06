"""
    The Tribonacci sequence Tn is defined as follows:

    T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

    Given n, return the value of Tn.
"""
def tribonacci(n):
    res = [0 for i in range(n + 1)]
    res[0] = 0
    res[1] = 1
    res[2] = 1

    for j in range(3, n + 1, 1):
        res[j] = sum(res[j - 3: j])

    return res[n]


print(f'tribonacci(4): {tribonacci(4)} ') #4
print(f'tribonacci(25): {tribonacci(25)} ') #1389537

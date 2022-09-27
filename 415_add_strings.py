"""
    Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

    You must solve the problem without using any built-in library for handling large integers (such as BigInteger).
    You must also not convert the inputs to integers directly.
"""
def addStrings(num1, num2):
        n1, n2 = len(num1) - 1, len(num2) - 1
        n_max = max(len(num1), len(num2))
        total = [0 for i in range(n_max)]
        to_add = 0

        for i in range(len(total) - 1, -1, -1):
            x1 = 0 if n1 < 0 else int(num1[n1])
            x2 = 0 if n2 < 0 else int(num2[n2])

            # print(f'x1: {x1}, x2:{x2}, to_add:{to_add}')
            total[i] = (x1 + x2 + to_add) % 10
            to_add = (x1+ x2 + to_add) // 10
            n1 -= 1
            n2 -= 1

        if to_add == 0:
            return "".join(str(i) for i in total)
        else:
            return str(to_add) + "".join(str(i) for i in total)

print(f'addStrings(num1 = "11", num2 = "123"):{addStrings(num1 = "11", num2 = "123")} ')#"134"
print(f'addStrings(num1 = "456", num2 = "77"):{addStrings(num1 = "456", num2 = "77")} ')#"533"
print(f'addStrings(num1 = "0", num2 = "0"):{addStrings(num1 = "0", num2 = "0")} ')#"0"

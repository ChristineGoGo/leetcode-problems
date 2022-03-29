"""
Given two binary strings a and b, return their sum as a binary string.
"""


        
# def add_binary(a,b):
#         """
#         :type a: str
#         :type b: str
#         :rtype: str
#         """
        
#         # my simple approach, turn a and b to decimal
#         # add the two decimals
#         # change the sum decimals back into binary
#         list_a, list_b = [], []        
#         decimal_a, decimal_b = 0, 0
#         # no need for two variables, use one variable called power
#         power = 0
#         n_a, n_b = len(a) - 1, len(b) - 1
#         result= []
        
#         # added binary and powers into a list then made the addition
#         # by loooping over the newly created list
#         # no need for the list        
#         for i in range(len(a)):
#                 list_a.append((a[i], 2 ** n_a))
#                 n_a -= 1 
                
#         for letter, binary in list_a:
#                 if letter == '1':
#                         decimal_a += binary
        
#         for i in range(len(b)):
#                 list_b.append((b[i], 2 ** n_b))
#                 n_b -= 1 
                
#         for letter, binary in list_b:
#                 if letter == '1':
#                         decimal_b += binary
                        

#         decimal_sum = decimal_a + decimal_b
        
#         while decimal_sum > 0:
#                 result.append(str(decimal_sum % 2))
#                 decimal_sum = decimal_sum // 2
                
        
#         result.reverse()
                        
#         return ''.join(result)


def to_decimal(a):
        decimal = 0
        power = len(a) - 1
        
        for i in range(len(a)):
                if a[i] != '0': decimal += 2 ** power
                power -= 1
        
        return decimal

def to_binary(a):
        result = []
        while a > 0:
                result.append(str(a % 2))
                a = a // 2
        
        result.reverse()       
        return ''.join(result)

def add_binary(a, b):
        # convert a , b to decimal
        sum_1 = to_decimal(a)
        sum_2 = to_decimal(b)
        
        # find the sum
        final_sum = sum_1 + sum_2
        
        # convert back to binary, return the result
        
        
        return to_binary(final_sum)


if __name__ == '__main__':
        # a = "10011011"
        a = "10011"
        b = "1"
        # print(addBinary(a, b))
        # print(to_decimal(a))        
        # print(add_binary(a, b))
        print(to_binary(20))
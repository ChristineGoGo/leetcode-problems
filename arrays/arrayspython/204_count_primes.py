"""
Given an integer n, return the number of prime numbers
that are strictly less than n

"""
## step one create a function to check if a number is prime or not
# ## my primitive solution
# def checkPrime(num):
#     if num > 1:
#         return False
#     elif num == 2 or num == 3:
#         return True
#     else:
#         mid = num//2
#         for i in range(2, mid):
#             if num % i == 0:
#                 return False
    
#     return True

#less dense solution
# only loop from 2 to suare root of the number
def checkPrime(num):
    if num > 1:
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                return False

        return num
    return False


## step two count the number of primes less than the integer n

def countPrimes(n):
    list_primes = []
    for number in range(2, n):
        if checkPrime(number):
            list_primes.append(checkPrime(number))
    return list_primes
            
if __name__ == '__main__':
    num = 10
    print(f"{num} primes are:" + str(countPrimes(num)) )
    
    # num = 2
    # print(f"{num} is:" + str(checkPrime(num)) )
    
    # num = 37
    # print(f"{num} is:" + str(checkPrime(num)) )
    
    # num = 121
    # print(f"{num} is:" + str(checkPrime(num)) )
    
    # num = -5
    # print(f"{num} is:" + str(checkPrime(num)) )
    
    # num = 5
    # print(f"{num} is:" + str(checkPrime(num)) )
    
    
    
    
    
    
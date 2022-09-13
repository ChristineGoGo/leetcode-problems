"""
    You are climbing a staircase. It takes n steps to reach the top.

    Each time you can either climb 1 or 2 steps. In how many distinct
    ways can you climb to the top?
    """

# # APPROACH 1 RECURSION
# def climbStairs(n, memo = {}):
#     if n in memo: return memo[n]
#     if n < 0: return 0
#     if n == 0: return 1

#     memo[n] = climbStairs(n - 1) + climbStairs(n - 2)
#     return memo[n]

# APPROACH 2 TABULATION
def climbStairs(n):
    res = [0 for i in range(n + 2)]
    res[0] = 1

    for i in range(n):
        res[i + 1] += res[i]
        res[i + 2] += res[i]

    return res[n]

print(f'climbStairs(2): {climbStairs(2)} ')#2
print(f'climbStairs(3): {climbStairs(3)} ')#3
print(f'climbStairs(6): {climbStairs(6)} ')#13
print(f'climbStairs(4): {climbStairs(4)} ')#5
print(f'climbStairs(5): {climbStairs(35)} ')

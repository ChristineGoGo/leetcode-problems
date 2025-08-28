"""
    You are given an integer array coins representing coins of
    different denominations and an integer amount representing a total amount of money.

    Return the fewest number of coins that you need to make up that amount.
    If that amount of money cannot be made up by any combination of the coins, return -1.

    You may assume that you have an infinite number of each kind of coin.
"""
# APPROACH 1 BRUTE FORCE
def coinChange(coins, amount):
    # print(f"amount: {amount}")
    if amount == 0: return 0
    if amount < 0 : return -1


    fewest = float("inf")
    for coin in coins:
        balance = amount - coin
        count = coinChange(coins, balance)
        if count == -1: continue
        count += 1
        fewest = min(count, fewest)
        # print(f"count: {count}, fewest: {fewest}")

    return fewest

# APPROACH 2 MEMOIZATION
def coinChange(coins, amount,d):
    if amount in d: return d[amount]
    if amount == 0: return 0
    if amount < 0 : return -1


    fewest = float("inf")
    for coin in coins:
        balance = amount - coin
        count = coinChange(coins, balance,d)
        if count == -1: continue
        count += 1
        fewest = min(count, fewest)
        # print(f"count: {count}, fewest: {fewest}")

    # print(f"amount: {amount},fewest: {fewest}")
    d[amount] = fewest if fewest != float("inf") else - 1
    print(f"d:{d}")
    return d[amount]

# APPROACH 3 TABULATION/DYNAMIC PROGRAMMING
def coinChange(coins, amount):
        amounts = [amount + 1 for i in range(amount + 1)]
        amounts[0] = 0
        for i in range(len(amounts) + 1):
            for coin in coins:
                f = i + coin
                if f <= amount:
                    amounts[f] = min(amounts[f], amounts[i] + 1)

        return amounts[amount] if amounts[amount] != amount + 1 else -1

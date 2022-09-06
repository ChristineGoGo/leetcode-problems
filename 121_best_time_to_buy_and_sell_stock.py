"""
    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
"""
# APPROACH 1 NAIVE BRUTE FORCE
# def maxProfit(prices):
#     n = len(prices)
#     profit = 0

#     for i in range(n):
#         for j in range(i + 1, n):
#             current_profit = prices[j] - prices[i]
#             if current_profit > 0:
#                 profit = max(current_profit, profit)

#     return profit

# # APPROACH 2 OPTIMIZED WITH HASH AND RANGE
# def maxProfit(prices):
#     n = len(prices) - 1
#     profit = 0
#     d = {}

#     for i in range(n, 0, -1):
#         current_profit = prices[i] - min(prices[0:i])
#         if current_profit > 0:
#             d[i] = current_profit

#     curr = max(d.values()) if len(d) > 0 else 0

#     return max(curr, profit)

# APPROACH 3 OPTIMIZED WITH DYNAMIC PROGRAMMING
def maxProfit(prices):
    profit = 0
    curr_min_price = float('inf')

    for price in prices:
        if price < curr_min_price:
            curr_min_price = price
        else:
            profit = max(profit, price - curr_min_price)
    return profit



print(f' maxProfit(prices = [7,1,5,3,6,4]): {maxProfit(prices = [7,1,5,3,6,4])}') #5
print(f' maxProfit(prices = [7,6,4,3,1]): {maxProfit(prices = [7,6,4,3,1])}') #0
print(f' maxProfit(prices = [7]): {maxProfit(prices = [7])}') #0
print(f' maxProfit(prices = [1, 2]): {maxProfit(prices = [1, 2])}') #1


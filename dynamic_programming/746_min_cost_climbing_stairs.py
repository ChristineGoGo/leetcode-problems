"""
    You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

    You can either start from the step with index 0, or the step with index 1.

    Return the minimum cost to reach the top of the floor.
"""
def minCostClimbingStairs(cost):
    res = [0 for i in range(len(cost) + 1)]

    for i in range(len(cost) - 1,-1, -1):
        # print(i)
        if i >= len(cost) - 2:
            res[i] = cost[i]
        else:
            res[i] = cost[i] + min(res[i + 1], res[i + 2])

    # print(res)
    return min(res[0], res[1])

print(f'minCostClimbingStairs([10, 15]): {minCostClimbingStairs([10, 15])}') #10
print(f'minCostClimbingStairs([10, 15, 20]): {minCostClimbingStairs([10, 15, 20])}') #15
print(f'minCostClimbingStairs([1,100,1,1,1,100,1,1,100,1]): {minCostClimbingStairs([1,100,1,1,1,100,1,1,100,1])}') #6

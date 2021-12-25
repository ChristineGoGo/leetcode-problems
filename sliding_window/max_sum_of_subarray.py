# find the maximum sum of a sub array of a fixed size of 3
import sys


def maxSum(arr, k):
    max_value = -sys.maxsize
    current_sum = 0
    for i in range(0, len(arr)):
        current_sum += arr[i]
        if i >= k-1:
            max_value = max(max_value, current_sum)
            current_sum -= arr[i - k + 1]

    return max_value


if __name__ == '__main__':
    arr1 = [4, 2, 1, 7, 8, 1, 2, 8, 1, 0]
    k = 3
    print(maxSum(arr1, k))

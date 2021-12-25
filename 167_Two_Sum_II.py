def twoSum(numbers, target):
    start = 0
    end = len(numbers) - 1
    while start < end:
        num_sum = numbers[start] + numbers[end]
        if num_sum < target:
            start += 1
        elif num_sum > target:
            end -= 1
        else:
            return start+1, end + 1


if __name__ == '__main__':
    numbers = [0, 0, 3, 4]
    target = 4
    print(twoSum(numbers, target))

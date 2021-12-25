def searchRange(nums, target, isFirst):
    start, end = 0, len(nums)
    l = []
    isFirst = False
    while start <= end:
        mid = (start + end) / 2
        if nums[mid] == target:
            if isFirst:
                if mid == start and nums[mid - 1] != target:
                    l.append(mid)
                    end = mid - 1
                    isFirst = True
            else:
                if mid == end and nums[mid + 1] != target:
                    l.append(mid)
                    start = mid + 1
        elif nums[mid] < target:
            start = mid + 1
        else:
            end = mid - 1

        start += 1

    if len(l) > 0:
        return l
    else:
        return [-1, -1]


if __name__ == '__main__':
    nums = [5, 7, 7, 8, 8, 10]
    target = 8
    print(searchRange(nums, target, False))

class Solution:
    def reverse(self, x: int) -> int:
        n_x = str(x)
        res = ''
        for i in range(len(n_x)- 1, -1, -1):
            res += n_x[i]
        res = res.removesuffix('-')
        res = int(res) if x > 0 else int(res) * -1
        if -2147483648 < res < 2147483647:
            return res
        else:
            return 0
class Solution:
    def myAtoi(self, s: str) -> int:
        # variables needed
        LOWER_BOUND = -2147483648
        UPPER_BOUND = 2147483647

        # store result
        res = ''

        # remove leading whitespaces
        new_s = s.strip()

        # handle the '-' and '+'
        signs = {'-': -1, '+':1 }
        # mult_by = signs['-'] if '-' in new_s else signs['+']
        mult_by = signs['-'] if new_s.find('-') == 0 else signs['+']
        new_s = new_s.removeprefix('-') if '-' in new_s else new_s.removeprefix('+')

        # read the characters until reaching a non digit value
        i = 0
        while i < len(new_s):
            if new_s[i].isdigit():
                res += new_s[i]
            else:
                break
            i += 1

        # convert the result into an integer
        if len(res) == 0: return 0
        res = int(res) * mult_by

        # return the result after clamping the digits together
        if res < LOWER_BOUND:
            return LOWER_BOUND
        elif res > UPPER_BOUND:
            return UPPER_BOUND
        else:
            return res

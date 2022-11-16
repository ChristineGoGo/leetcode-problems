"""
    Given a string containing digits from 2-9 inclusive,
    return all possible letter combinations that the number could represent.
    Return the answer in any order.

    A mapping of digits to letters (just like on the telephone buttons) is given below.
    Note that 1 does not map to any letters.



    Example 1:

    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    Example 2:

    Input: digits = ""
    Output: []

    Example 3:

    Input: digits = "2"
    Output: ["a","b","c"]
"""
# brute force
# def letterLooper(mapping):
#     n = len(mapping)
#     indices = list(range(n))
#     if n == 2:
#         return list(x + y for x in mapping[indices[0]] for y in mapping[indices[1]])
#     if n == 3:
#         v1 = list(x + y for x in mapping[indices[0]] for y in mapping[indices[1]])
#         return list(x + y for x in v1 for y in mapping[indices[2]])
#     if n == 4:
#         v1 = list(x + y for x in mapping[indices[0]] for y in mapping[indices[1]])
#         v2 = list(x + y for x in v1 for y in mapping[indices[2]])
#         return list(x + y for x in v2 for y in mapping[indices[3]])

# def letterCombinations(digits):
#     n = len(digits)

#     m = {
#         "2": ["a", "b", "c"],
#         "3": ["d", "e", "f"],
#         "4": ["g", "h", "i"],
#         "5": ["j", "k", "l"],
#         "6": ["m", "n", "o"],
#         "7": ["p", "q", "r", "s"],
#         "8": ["t", "u", "v"],
#         "9": ["w", "x", "y", "z"]
#     }

#     if n == 0: return []
#     if n == 1: return m[digits[0]]

#     digits_m = []
#     for i in range(n):
#         digits_m.append(m[digits[i]])

#     return letterLooper(digits_m)

# backtracking
# def letterCombinations(digits):
#     combs = []
#     m = {
#         '2': 'abc',
#         '3': 'def',
#         '4': 'ghi',
#         '5': 'jkl',
#         '6': 'mno',
#         '7': 'pqrs',
#         '8': 'tuv',
#         '9': 'wxyz'
#     }

#     if len(digits) == 0: return combs
#     def helper(index, path):
#         # basecase
#         if len(path) == len(digits):
#             combs.append("".join(path))
#             return

#         curr_letters = m[digits[index]]
#         for letter in curr_letters:
#             path.append(letter)
#             helper(index + 1, path)
#             path.pop()

#     helper(0, [])

#     return combs

# lists and for loops more elegant
def letterCombinations(digits):
    combs = [[]]
    n = len(digits)
    m = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    }

    if n == 0: return []
    digits_m = [m[digits[x]] for x in range(n)]
    for letters in digits_m:
        combs = [y + [letter] for y in combs for letter in letters]

    combs = ["".join(item) for item in combs]
    return combs









# tests
print(f'letterCombinations(digits="23"): {letterCombinations(digits="23")}') #["ad","ae","af","bd","be","bf","cd","ce","cf"]
print(f'letterCombinations(digits=""): {letterCombinations(digits="")}') #[]
print(f'letterCombinations(digits="2"): {letterCombinations(digits="2")}') #["a", "b", "c"]
print(f'letterCombinations(digits="234"): {letterCombinations(digits="234")}')
# #["adg","adh","adi","aeg","aeh","aei","afg","afh","afi","bdg","bdh","bdi","beg","beh","bei","bfg","bfh","bfi","cdg","cdh","cdi","ceg","ceh","cei","cfg","cfh","cfi"]
print(f'letterCombinations(digits="2345"): {letterCombinations(digits="2345")}')
#["adgj", "adgk","adgl" "adhj", "adhk", "adhl", "adij", "adik", "adil",
# "aegj", "aegk","aegl", "aehj", "aehk", "aehl", "aeij", "aeik", "aeil",
# "afgj", "afgk", "afgl", "afhj", "afhk", "afhl", "afij", "afik", "afil",
# "bdgj", "bdgk","bdgl", "bdhj", "bdhk", "bdhl", "bdij","bdik", "bdil","begj","begk",
# "begl","behj", "behk","behl","beij","beik", "beil", "bfgj","bfgk", "bfgl",
# "bfhj", "bfhk", "bfhl", "bfij", "bfik", "bfil", "cdgj","cdgk", "cdgl", "cdhj",
# "cdhk", "cdhl", "cdij", "cdik", "cdil", "cegj", "cegk", "cegl", "cehj", "cehk",
# "cehl", "ceij", "ceik", "ceil", "cfgj", "cfgk", "cfgl", "cfhj","cfhk", "cfhl",
# "cfij", "cfik", "cfil"]



"""
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R

    And then read line by line: "PAHNAPLSIIGYIR"

    Write the code that will take a string and make this conversion given a number of rows:

    string convert(string s, int numRows);

"""
def convert(s, numRows):
    n = len(s)
    # if string or numRows has one value
    if n == 1 or numRows == 1: return s
    """
        curr_row = corresponds to the row
        to which the string character
        belongs to
        d = stores all the characters in
        the string and which row they'll
        be placed in
        res = stores the resulting string
        up - boolean value to tell if we
        are going down the rows(current_row
        + 1 or going up the rows(current_row - 1
        ))
    """
    curr_row, up, d, res = 0, False, {}, ''

    for i in range(numRows):
        d[i] = []

    for i in range(n):
        d[curr_row].append(s[i])
        if not up:
            curr_row += 1
        else:
            curr_row -= 1

        if curr_row == numRows - 1 or curr_row == 0:
            up = not up

    for k, v in d.items():
        for letter in v:
            res += letter

    return res



# tests
# s = "PAYPALISHIRING"
# numRows = 3
# print(f"convert(s, numRows): {convert(s, numRows)}") # "PAHNAPLSIIGYIR"

# s = "PAYPALISHIRING"
# numRows = 4
# print(f"convert(s, numRows): {convert(s, numRows)}") # "PINALSIGYAHRPI"

# s = "AB"
# numRows = 1
# print(f"convert(s, numRows): {convert(s, numRows)}") # "AB"
s = "eatthestrawberry"
numRows = 3
print(f"convert(s, numRows): {convert(s, numRows)}") # "ehreatetabrytswr"


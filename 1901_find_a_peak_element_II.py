"""
    A peak element in a 2D is an element
    that is strictly greater than all of its
    adjacent neighbours to the left, right, top,
    and bottom.

    Given a 0 indexed m * n matrix mat where no two adjacent
    cells are equal find any peak element mat[i][j] and return
    the length 2 array [i, j].

    You may assume that the entire matrix is surrounded by an
    outer perimeter with the value -1 in each cell

    You must write an algorithm that runs in 0(m log(n)) or
    O(n log(n)) time

    Example 1
    mat = [[1, 4], [3, 2]]
    output = [0, 1]
    explanation: both 3 and 4 are peak elements

    Example 2
    mat = [[10, 20, 15], [21, 30, 14], [7, 16, 32]]
    output = [1, 1]
    explanation: both 30 and 32 are peak elements

    Constraints:
        m == mat.length
        n == mat[i].length
        1 <= m, n <= 500
        1 <= mat[i][j] <= 10^5
        No two adjacent cells are equal
"""
def findPeakGrid(mat):
    m = len(mat)
    for i in range(m):
        j = findJ(mat[i])
        if checkBottom(i, j, mat) and checkTop(i, j, mat):
            return [i, j]

def checkTop(i, j, mat):
    """
    Args:
        i (integer): the row of 2D matrix
        j (integer): the column of the matrix
        mat (list of lists): a 2D matrix

    Returns:
        boolean : returns True if the top value
        is greater than mat[i - 1][j]
    """
    val = mat[i][j]
    top = mat[i - 1][j] if i > 0 else -1
    if val > top:
        return True
    else:
        return False

def checkBottom(i, j, mat):
    """
    Args:
        i (integer): the row of 2D matrix
        j (integer): the column of 2D matrix
        mat (list of lists): 2D matrix list of lists

    Returns:
        boolean : returns True if the bottom(mat[i + 1][j])
        is greater than mat[i][j]
    """
    val = mat[i][j]
    # bottom value is -1 when reached the last row of mat
    # else it is mat[i + 1][j]
    bottom = mat[i + 1][j] if i < len(mat) - 1 else -1
    if val > bottom:
        return True
    else:
        return False

def findJ(arr):
    """
    Args:
        arr (list): a list of integers

    Returns:
        integer: returns the index of the integer which
        is greater than its neighbors(peak)
    """
    n = len(arr)
    curr_max = float("-inf")
    if n == 1:
        return 0

    for j in range(n):
        if arr[j] > curr_max:
            curr_max = arr[j]
            curr_j = j
    return curr_j


# print(findPeakGrid(mat=[
#     [55, 77, 9,  50, 49, 77, 60, 68, 33, 71, 2,  88, 93, 15, 88, 69, 97, 35, 99, 83, 44, 15,  38],
#     [56, 21, 59, 1,  93, 34, 65, 98, 23, 65, 14, 81, 39, 82, 65, 78, 26, 20, 48, 98, 21, 70,  100],
#     [68, 1,  77, 42, 63,  3, 15, 47, 40, 31,  8, 31, 73, 11, 94, 63,  9, 98, 69, 99, 17, 85,  61],
#     [71, 22, 34, 68, 78, 55, 28, 70, 97, 94, 89, 26, 92, 40, 52, 86, 84, 48, 57, 67, 58, 16,  32],
#     [29, 9,  44, 3,  76, 71, 36, 76, 29, 1,  10, 91, 81, 8,  30, 9,  5,  43, 10, 68, 31, 36,  86],
#     [63, 28, 70, 17, 93, 74, 61, 32, 61, 53, 25, 13, 85, 56, 46, 55, 53, 66, 94,  7, 87, 84,  83],
#     [13, 8,  52, 94, 44, 14, 32, 25, 69, 58, 18, 55, 24, 36, 60, 32, 10, 57, 71, 13,  7, 70,  2]
# ]))

print(findPeakGrid(mat=[[1, 4], [3, 2]]))

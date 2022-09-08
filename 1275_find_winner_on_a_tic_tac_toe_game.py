"""
Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

    Players take turns placing characters into empty squares ' '.
    The first player A always places 'X' characters, while the second player B always places 'O' characters.
    'X' and 'O' characters are always placed into empty squares, never on filled ones.
    The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
    The game also ends if all squares are non-empty.
    No more moves can be played if the game is over.

Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on
grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw
return "Draw". If there are still movements to play return "Pending".

You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, and A will play first.

 """
# #  APPROACH 1 MISSING DETAILED LOGIC
# def tictactoe(moves):
#     results = {"A":[], "B": []}

#     for index, move in enumerate(moves):
#         if (index % 2 == 0):
#             results["A"].append(move)
#         else:
#             results["B"].append(move)

#     row_sum, col_sum, total_sum = 0, 0, 0
#     for k, v in results.items():
#         for i in v:
#             row_sum += i[0]
#             col_sum += i[1]
#             total_sum += 1

#         # winner
#         if row_sum == 3 or col_sum == 3:
#             return k
#         #draw
#         elif total_sum == 9:
#             return "Draw"
#         else:
#             row_sum, col_sum = 0, 0


#     return "Pending"

#  APPROACH 2 BRUTE FORCE
# def tictactoe(moves):
#     n = 3
#     results = [[0 for i in range(n)] for j in range(n)]

#     for index, move in enumerate(moves):
#         # identify rows and columns
#         row = move[0]
#         column = move[1]

#         if (index % 2 == 0):
#             results[row][column] = "X"

#             tally_row = []
#             tally_column = []
#             tally_horizontal = []
#             tally_anti_horizontal = []

#             # check if winner in row
#             for item in results[row]:
#                 tally_row.append(item)
#             if tally_row.count("X") == n: return "A"

#             # check if winner in column
#             for row in results:
#                 tally_column.append(row[column])

#             if tally_column.count("X") == n: return "A"

#             # check if winner in horizontal
#             for i, row in enumerate(results):
#                 tally_horizontal.append(row[i])

#             if tally_horizontal.count("X") == n: return "A"

#             # check if winner in anti horizontal
#             for i, row in enumerate(results ):
#                 tally_anti_horizontal.append(row[n - 1 - i])

#             if tally_anti_horizontal.count("X") == n: return "A"
#         else:
#             results[row][column] = "O"

#             tally_row = []
#             tally_column = []
#             tally_horizontal = []
#             tally_anti_horizontal = []

#             # check if winner in row
#             for item in results[row]:
#                 tally_row.append(item)
#             if tally_row.count("O") == n: return "B"

#             # check if winner in column
#             for row in results:
#                 tally_column.append(row[column])
#             if tally_column.count("O") == n: return "B"

#             # check if winner in horizontal
#             for i, row in enumerate(results):
#                 tally_horizontal.append(row[i])

#             if tally_horizontal.count("O") == n: return "B"

#             # check if winner in anti horizontal
#             for i, row in enumerate(results):
#                 tally_anti_horizontal.append(row[n - 1 - i])

#             if tally_anti_horizontal.count("O") == n: return "B"

#     return results

# APPROACH 2 BRUTE FORCE
def tictactoe(moves):
    n = 3
    results = [[0 for i in range(n)] for j in range(n)]

    for i, move in enumerate(moves):
        row = move[0]
        col = move[1]

        if i % 2 == 0:
            results[row][col] = "X"
        else:
            results[row][col] = "O"

        # look for winners
        tally_row = []
        tally_column = []
        tally_horizontal = []
        tally_anti_horizontal = []

        for item in results[row]:
            tally_row.append(item)

        for row in results:
            tally_column.append(row[col])

        for i, row in enumerate(results):
            tally_horizontal.append(row[i])

        for i, row in enumerate(results):
            tally_anti_horizontal.append(row[n - 1 - i])

        if tally_row.count("X") == n:
            return "A"
        elif tally_row.count("O") == n:
            return "B"

        if tally_column.count("X") == n:
            return "A"
        elif tally_column.count("O") == n:
            return "B"

        if tally_horizontal.count("X") == n:
            return "A"
        elif tally_horizontal.count("O") == n:
            return "B"

        if tally_anti_horizontal.count("X") == n:
            return "A"
        elif tally_anti_horizontal.count("O") == n:
            return "B"


    if 0 in (item for result in results for item in result):
        return "Pending"
    else:
        return "Draw"




print(f'{tictactoe(moves = [[1,0],[0,1],[1,2],[1,1],[2,0],[2,1]])}')# "B"
print(f'{tictactoe(moves = [[2,2],[1,1],[0,2],[0,1],[1,2]])}')# "A"
print(f'{tictactoe(moves = [[0,1],[1,0],[2,1],[1,1],[2,0],[1,2]])}')# "B"
print(f'{tictactoe(moves = [[0,0],[1,1],[0,2],[2,0],[0,1]])}')# "A"
# horizontal tests
print(f'{tictactoe(moves = [[0,0],[2,0],[1,1],[2,1],[2,2]])}')# "A"
print(f'{tictactoe(moves = [[2,0],[0,0],[0,1],[1,1],[0,2],[2, 2]])}')# "B"
# anti horizontal tests
print(f'{tictactoe(moves = [[2,0],[2,2],[0,2],[0,1],[1,1]])}')# "A"
print(f'{tictactoe(moves = [[2,1],[2,0],[0,1],[1,1],[0,0],[0,2]])}')# "B"

print(f'{tictactoe(moves = [[0,0],[1,1]])}')# "Pending"
print(f'{tictactoe(moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]])}')# "B"
print(f'{tictactoe(moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]])}')# "Draw"


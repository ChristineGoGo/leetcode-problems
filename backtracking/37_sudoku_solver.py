"""
    Write a program to solve a Sudoku puzzle by filling the empty cells.

    A sudoku solution must satisfy all of the following rules:

        Each of the digits 1-9 must occur exactly once in each row.
        Each of the digits 1-9 must occur exactly once in each column.
        Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

    The '.' character indicates empty cells.
"""

class Solution:
    DIGIT = 9
    GRID = 3
    EMPTY = "."
    ALL_DIGITS = set(str(num) for num in range(1, DIGIT + 1))
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        self.search(board)

    def is_valid(self, board):
        #validate each row
        for row in self.get_rows(board):
            if not set(row) == self.ALL_DIGITS: return False
        #validate each column
        for col in self.get_cols(board):
            if not set(col) == self.ALL_DIGITS: return False
        #validate each grid
        for grid in self.get_grids(board):
            if not set(grid) == self.ALL_DIGITS: return False
        return True

    def get_candidates(self, board, row, col):
        used_digits = set(self.ALL_DIGITS).copy()
        # remove digits used by row
        used_digits -= set(self.get_kth_row(board, row))
        # remove digits used by column
        used_digits -= set(self.get_kth_col(board, col))
        # remove digits used by the current grid
        used_digits -= set(self.get_kth_grid(board, row, col))

        candidates = used_digits
        return candidates

    def search(self, board):
        # base case
        if self.is_valid(board): return True

        #recursion
        for row_idx, row in enumerate(board):
            for col_idx, item in enumerate(row):
                if item == self.EMPTY:
                    for candidate in self.get_candidates(board, row_idx, col_idx):
                        board[row_idx][col_idx] = candidate
                        res = self.search(board)
                        if res:
                            return True
                        else:
                            board[row_idx][col_idx] = self.EMPTY
                    return False
        # if the board has no empty spots to begin with
        return True
    # Helper functions
    def get_rows(self, board):
        for i in range(self.DIGIT):
            yield board[i]
    def get_cols(self, board):
        for i in range(self.DIGIT):
            res = []
            for j in range(self.DIGIT):
                res.append(board[j][i])
            yield res
    def get_grids(self, board):
        row_start, row_end = 0, self.GRID
        col_start, col_end = 0, self.GRID
        for i in range(self.DIGIT):
            res = []
            for row in range(row_start, row_end):
                for col in range(col_start, col_end):
                    res.append(board[row][col])
            if col_end < self.DIGIT:
                col_start += self.GRID
                col_end += self.GRID
            else:
                col_start, col_end = 0, self.GRID
                row_start += self.GRID
                row_end += self.GRID
            yield res

    def get_kth_grid(self, board, row, col):
        res = []
        if 0 <= row < self.GRID and 0 <= col < self.GRID:
            res = [board[i][j] for i in range(self.GRID) for j in range(self.GRID)]
        elif 0 <= row < self.GRID and self.GRID <= col < self.GRID * 2:
            res = [board[i][j] for i in range(self.GRID) for j in range(self.GRID, self.GRID * 2)]
        elif 0 <= row < self.GRID and self.GRID * 2 <= col < self.GRID * 3:
            res = [board[i][j] for i in range(self.GRID) for j in range(self.GRID * 2, self.GRID * 3 )]
        elif self.GRID <= row < self.GRID * 2 and 0 <= col < self.GRID:
            res = [board[i][j] for i in range(self.GRID, self.GRID * 2) for j in range(self.GRID)]
        elif self.GRID <= row < self.GRID * 2 and self.GRID <= col < self.GRID * 2:
            res = [board[i][j] for i in range(self.GRID, self.GRID * 2) for j in range(self.GRID, self.GRID * 2)]
        elif self.GRID <= row < self.GRID * 2 and self.GRID * 2 <= col < self.GRID * 3:
            res = [board[i][j] for i in range(self.GRID, self.GRID * 2) for j in range(self.GRID * 2, self.GRID * 3 )]
        elif self.GRID * 2 <= row < self.GRID * 3 and 0 <= col < self.GRID:
            res = [board[i][j] for i in range(self.GRID * 2,self.GRID * 3 ) for j in range(self.GRID)]
        elif self.GRID * 2 <= row < self.GRID * 3 and self.GRID <= col < self.GRID * 2:
            res = [board[i][j] for i in range(self.GRID * 2,self.GRID * 3 ) for j in range(self.GRID, self.GRID * 2)]
        elif self.GRID * 2 <= row < self.GRID * 3 and self.GRID * 2 <= col < self.GRID * 3:
            res = [board[i][j] for i in range(self.GRID * 2,self.GRID * 3 ) for j in range(self.GRID * 2, self.GRID * 3)]
        return res
    def get_kth_row(self, board, row):
        return board[row]
    def get_kth_col(self, board, col):
        return [board[j][col] for j in range(self.DIGIT)]



# solution
# board = [
#     ["9", "7", "2", "1", "3", "4", "8", "6", "5"],
#     ["4", "8", "6", "7", "5", "9", "2", "3", "1"],
#     ["5", "3", "1", "6", "2","8", "7", "4", "9"],
#     ["1", "2", "4", "9", "6", "5", "3", "8","7"],
#     ["3", "6", "9", "8", "7", "2", "1", "5","4"],
#     ["7", "5", "8", "3", "4", "1", "6", "9","2"],
#     ["2", "9", "7", "4", "8", "3", "5", "1","6"],
#     ["6", "1", "3", "5", "9", "7", "4", "2","8"],
#     ["8", "4", "5", "2", "1", "6", "9", "7","3"],
# ]


board = [
    ["9", ".", ".", ".", ".", "4", "8", "6", "5"],
    ["4", "8", ".", "7", ".", "9", "2", ".", "."],
    ["5", "3", ".", ".", ".",".", "7", ".", "."],
    [".", "2", ".", ".", "6", "5", ".", ".","."],
    ["3", ".", ".", ".", "7", ".", ".", ".","4"],
    [".", ".", ".", "3", "4", ".", ".", "9","."],
    [".", ".", "7", ".", ".", ".", ".", "1","6"],
    [".", ".", "3", "5", ".", "7", ".", "2","8"],
    ["8", "4", "5", "2", ".", ".", ".", ".","3"],
]
# t = Solution(board)
# t.solveSudoku(board)


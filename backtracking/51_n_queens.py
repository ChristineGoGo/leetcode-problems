"""
    The n-queens puzzle is the problem of placing n queens
    on an n x n chessboard such that no two queens attack each other.

    Given an integer n, return all distinct solutions to the
    n-queens puzzle. You may return the answer in any order.

    Each solution contains a distinct board configuration of
    the n-queens' placement, where 'Q' and '.' both indicate
    a queen and an empty space, respectively.
"""
class Solution:
    def solveNQueens(self, n):
        solutions = []
        state = []
        self.search(solutions, state, n)
        return self.to_strings(solutions, n)

    def __str__(self):
        return self.solutions

    def valid_state(self, state, n):
        return len(state) == n

    def get_candidates(self, state, n):
        if not state: return set(range(n))
        candidates = set(range(n))
        position = len(state)

        for row, col in enumerate(state):
            candidates.discard(col)
            dist = position - row
            candidates.discard(col + dist)
            candidates.discard(col - dist)

        return candidates

    def search(self, solutions, state, n):
        # print(f"state: {state}")
        if self.valid_state(state, n):
            solutions.append(state.copy())
            # print(f"solutions: {solutions}")
            return
        for candidate in self.get_candidates(state, n):
            state.append(candidate)
            self.search(solutions, state, n)
            state.pop()

    def to_strings(self, solutions, n):
        result = []
        for item in solutions:
            res = []
            for i in item:
                st = "." * i + "Q" + "." * (n - i - 1)
                res.append(st)
            result.append(res)
        return result


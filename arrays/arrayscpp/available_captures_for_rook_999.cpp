/*
    You are given an 8 x 8 matrix representing a chessboard. There is exactly one white rook represented by 'R',
    some number of white bishops 'B', and some number of black pawns 'p'. Empty squares are represented by '.'.

    A rook can move any number of squares horizontally or vertically (up, down, left, right) until it reaches another
    piece or the edge of the board. A rook is attacking a pawn if it can move to the pawn's square in one move.

    Note: A rook cannot move through other pieces, such as bishops or pawns. This means a rook cannot attack a pawn
    if there is another piece blocking the path.

    Return the number of pawns the white rook is attacking.


    Example 1:


    Input: board = [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],
    [".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]

    Output: 3

    Explanation:

    In this example, the rook is attacking all the pawns.

    Example 2:
    Input: board = [[".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],
    [".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]

    Output: 0

    Explanation:

    The bishops are blocking the rook from attacking any of the pawns.

    Example 3:


    Input: board = [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],
    ["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],
    [".",".",".",".",".",".",".","."]]

    Output: 3

    Explanation:

    The rook is attacking the pawns at positions b5, d6, and f5.



    Constraints:

    board.length == 8
    board[i].length == 8
    board[i][j] is either 'R', '.', 'B', or 'p'
    There is exactly one cell with board[i][j] == 'R'

*/

// APPROACH: Determmine the row and column that the Rook is at (R)
// go up until Bishops(B) is found or pawn(p) is found, if pawn is found
// add to the pawns attacked else if Bishop is found break loop
// Go to right, left and down as well.
// Return the total pawns attacked
int numRookCaptures(vector<vector<char>>& board) {
    int rookColumn; int rookRow; ; int totalPawns = 0;
    // find row and column of Rook
    for (int r = 0; r < 8; r++ ) {
        for (int c = 0; c < 8; c++) {
            if (board[r][c] == 'R') {
                rookRow = r;
                rookColumn = c;
                break;
            }
        }
    }

    // left
    for (int c = rookColumn; c >= 0; c--) {
        if (board[rookRow][c] == 'B'){
            break;
        } else if (board[rookRow][c] == 'p'){
            // cout << "found left pawn! \n";
            totalPawns++;
            break;
        }
    }
    // cout << "left is: " << totalPawns << "\n";

    // right
    for (int c = rookColumn; c < 8; c++) {
        if (board[rookRow][c] == 'B'){
            break;
        } else if (board[rookRow][c] == 'p'){
            // cout << "found right pawn! \n";
            totalPawns++;
            break;
        }
    }

    // cout << "right is: " << totalPawns << "\n";

    // up
    for (int r = rookRow; r >= 0; r--) {
        if (board[r][rookColumn] == 'B'){
            break;
        } else if (board[r][rookColumn] == 'p'){
            // cout << "found up pawn! \n";
            totalPawns++;
            break;
        }
    }
    // cout << "up is: " << totalPawns << "\n";

    // down
    for (int r = rookRow; r < 8; r++) {
        if (board[r][rookColumn] == 'B'){
            break;
        } else if (board[r][rookColumn] == 'p'){
            // cout << "found down pawn! \n";
            totalPawns++;
            break;
        }
    }
    // cout << "down is: " << totalPawns << "\n";

    return totalPawns;

}


/*

    You are given two positive integers x and y, denoting the number of
    coins with values 75 and 10 respectively.

    Alice and Bob are playing a game. Each turn, starting with Alice, 
    the player must pick up coins with a total value 115. If the player is
    unable to do so, they lose the game.

    Return the name of the player who wins the game if both players play optimally.

    

    Example 1:

    Input: x = 2, y = 7

    Output: "Alice"

    Explanation:

    The game ends in a single turn:

    Alice picks 1 coin with a value of 75 and 4 coins with a value of 10.
    Example 2:

    Input: x = 4, y = 11

    Output: "Bob"

    Explanation:

    The game ends in 2 turns:

    Alice picks 1 coin with a value of 75 and 4 coins with a value of 10.
    Bob picks 1 coin with a value of 75 and 4 coins with a value of 10.
    

    Constraints:

    1 <= x, y <= 100
*/

/*
 * APPROACH: Keep summing up 75 and 10 to a sum of 115, making sure to
 * keep track of the current player until there are no more coins.
 */



public class findTheWinningPlayerInCoinGame_3222 {
    public static String winningPlayer(int x, int y) {
        int isAlice = 0;
        int totalX = (x * 75);
        int totalY = (y * 10);

        while (totalX >= 75 && totalY >= 40) {
            isAlice++;
            x--;
            y -= 4;
            totalX = (75 * x);
            totalY = (10 * y);
        }
        // System.out.println(isAlice);
        return isAlice % 2 != 0 ? "Alice" : "Bob";
    }

    public static void main(String[] args) {
        System.out.println(winningPlayer(2, 7));
    }
    
}

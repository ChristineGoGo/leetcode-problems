/*
Alice and Bob are playing a game where they take turns removing stones from a pile, with Alice going first.

Alice starts by removing exactly 10 stones on her first turn.
For each subsequent turn, each player removes exactly 1 fewer stone than the previous opponent.
The player who cannot make a move loses the game.

Given a positive integer n, return true if Alice wins the game and false otherwise.

 

Example 1:

Input: n = 12

Output: true

Explanation:

Alice removes 10 stones on her first turn, leaving 2 stones for Bob.
Bob cannot remove 9 stones, so Alice wins.
Example 2:

Input: n = 1

Output: false

Explanation:

Alice cannot remove 10 stones, so Alice loses.
 

Constraints:

1 <= n <= 50
*/

/*
 * APPROACH : Immediately return false if the number is less than 10.
 * create variable to track the total stones(total) and Bob' stones
 * Perform operation where you subtract 10 from total then 1 less than
 * 10 etc until Bob's stones cannot match 1 less than Alices. Return true
 * else return false since Alice is not winning
 */

public class stoneRemovalGame_3360 {
    public static boolean canAliceWin(int n) {
        int total = n;
        int aliceStones = 10;
        int bobStones;

        while (total > 0) {
            if (total < aliceStones) {
                return false;
            }

            total -= aliceStones;
            aliceStones--;
            bobStones = aliceStones;

            if (total < bobStones) {
                return true;
            }
            total -= bobStones;
            bobStones--;
            aliceStones = bobStones;
        }

        return false;
    }

    public static void main (String[] args) {
        System.out.println(canAliceWin(12));
    }
}

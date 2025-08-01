/*

    You are given two strings, coordinate1 and coordinate2,
    representing the coordinates of a square on an 8 x 8 chessboard.

    Below is the chessboard for reference.



    Return true if these two squares have the same color and false otherwise.

    The coordinate will always represent a valid chessboard square. The coordinate
    will always have the letter first (indicating its column), and the number second
    (indicating its row).

    

    Example 1:

    Input: coordinate1 = "a1", coordinate2 = "c3"

    Output: true

    Explanation:

    Both squares are black.

    Example 2:

    Input: coordinate1 = "a1", coordinate2 = "h3"

    Output: false

    Explanation:

    Square "a1" is black and "h3" is white.

    

    Constraints:

    coordinate1.length == coordinate2.length == 2
    'a' <= coordinate1[0], coordinate2[0] <= 'h'
    '1' <= coordinate1[1], coordinate2[1] <= '8'
*/

import java.util.HashMap;
import java.util.Map;

public class checkIfTwoChessboardSquaresHaveTheSameColor_3274 {
    public boolean checkTwoChessboards(String coordinate1, String coordinate2) {
        // create a hashMap to track the column numbers
        // if the sum of the columns and rows is even
        // then the coordinate color is black
        // if the sum is odd the coordinate color is black

        Map<String, Integer> tracker = new HashMap<>();
        tracker.put("a", 1);
        tracker.put("b", 2);
        tracker.put("c", 3);
        tracker.put("d", 4);
        tracker.put("e", 5);
        tracker.put("f", 6);
        tracker.put("g", 7);
        tracker.put("h", 8);


        //find the number of the column of the coordinates
        int num1Cor1 = tracker.get(coordinate1.charAt(0) + "");
        int num2Cor1 = Integer.parseInt(coordinate1.charAt(1) + "");

        int num1Cor2 = tracker.get(coordinate2.charAt(0) + "");
        int num2Cor2 = Integer.parseInt(coordinate2.charAt(1) + "");

        // find the respective sums and thus the colors
        String coordinate1Color = (num1Cor1 + num2Cor1) % 2 == 0 ? "b" : "w";
        String coordinate2Color = (num1Cor2 + num2Cor2) % 2 == 0 ? "b" : "w";



        return coordinate2Color.equals(coordinate1Color);
    }

    public static void main(String[] args) {
        String a = "b";
        String b = "b";

        System.out.println(a.equals(b));
    }
    
}

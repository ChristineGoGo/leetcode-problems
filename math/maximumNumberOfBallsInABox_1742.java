import java.util.HashMap;
import java.util.Map;
/*
    You are working in a ball factory where you have n balls numbered 
    from lowLimit up to highLimit inclusive (i.e., n == highLimit - lowLimit + 1), 
    and an infinite number of boxes numbered from 1 to infinity.

    Your job at this factory is to put each ball in the box with a number equal to 
    the sum of digits of the ball's number. For example, the ball number 321 will 
    be put in the box number 3 + 2 + 1 = 6 and the ball number 10 will be put in 
    the box number 1 + 0 = 1.

    Given two integers lowLimit and highLimit, return the number of balls in the box
     with the most balls.

    

    Example 1:

    Input: lowLimit = 1, highLimit = 10
    Output: 2
    Explanation:
    Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
    Ball Count:  2 1 1 1 1 1 1 1 1 0  0  ...
    Box 1 has the most number of balls with 2 balls.
    Example 2:

    Input: lowLimit = 5, highLimit = 15
    Output: 2
    Explanation:
    Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
    Ball Count:  1 1 1 1 2 2 1 1 1 0  0  ...
    Boxes 5 and 6 have the most number of balls with 2 balls in each.
    Example 3:

    Input: lowLimit = 19, highLimit = 28
    Output: 2
    Explanation:
    Box Number:  1 2 3 4 5 6 7 8 9 10 11 12 ...
    Ball Count:  0 1 1 1 1 1 1 1 1 2  0  0  ...
    Box 10 has the most number of balls with 2 balls.
    

    Constraints:

    1 <= lowLimit <= highLimit <= 105
 */



public class maximumNumberOfBallsInABox_1742 {
    public int digitCount(int num) {
        int count = 0;
        if (num / 10 == 0) {
            count = num;
        } else {
            while (num > 0) {
                int current = num % 10;
                count += current;
                num /= 10; 
            }
        }
        return count;
    }

    public int countBalls(int lowLimit, int highLimit) {
        int max = 1;
        Map<Integer, Integer> m = new HashMap<>();


        while (lowLimit <= highLimit) {
            if (m.get(digitCount(lowLimit)) == null) {
                m.put(digitCount(lowLimit), 1);
            } else {
                System.out.println(max);
                int current = m.get(digitCount(lowLimit));
                current++;
                m.put(digitCount(lowLimit), current);
                if (current > max) {
                    max = current;
                }
            }
            lowLimit++;

        }

        return max;
    }
}

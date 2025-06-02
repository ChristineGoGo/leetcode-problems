/*
*A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.
*Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.
*Example 1:
*Input: n = 5
*Output: 2
*Explanation: The square triples are (3,4,5) and (4,3,5).
*Example 2:
*Input: n = 10
*Output: 4
*Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10). 
*/
/*
 * APPROACH: Use 2 for loops to find a and b and then add 2 to the total square
 * triples if the square root of the sum of the squares of a and b is equal to c
 */
public class countSquareSumTriples_1925 {
    public static int countTriples(int n) {
        int total = 0;

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                double res = Math.sqrt((i * i) + (j * j));
                if ((res <= n) && (res % 1 == 0)) {
                    total += 2;
                }

            }
        }
        return total;
    }
    public static void main(String[] args) {
        int test = 10;
        System.out.println(countTriples(test));
    }
    
}

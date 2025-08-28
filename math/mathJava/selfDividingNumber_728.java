
import java.util.ArrayList;
import java.util.List;

/*
 * A self-dividing number is a number that is divisible by every digit it contains.
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
 * A self-dividing number is not allowed to contain the digit zero.
 * Given two integers left and right, return a list of all the 
 * self-dividing numbers in the range [left, right] (both inclusive).
 * Example 1:
 * Input: left = 1, right = 22
 * Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]
 * Example 2:
 * Input: left = 47, right = 85
 * Output: [48,55,66,77]
 */

 /*
  * APPROACH: loop while left <= right, create a function to verify if a number is
  * self dividing. If so, add to the result array.
  */


public class selfDividingNumber_728 {
    public static List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> result =  new ArrayList<>();

        while (left <= right) {
            if (isSelfDividing(left)) {
                result.add(left);
            }
            left++;
        }
        return result;
    }


    public static boolean isSelfDividing(int num) {
        int n = num;
        while (n > 0){
            int current = n % 10;
            if (current == 0 || n == 0 ) {
                return false;
            }else if (num % current != 0) {
                return false;
            }
            n /= 10;
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(selfDividingNumbers(47, 85));
    }

    
}

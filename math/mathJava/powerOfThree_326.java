public class powerOfThree_326 {
    public static boolean isPowerOfThree(int n) {
        int num = n;
        while (num > 1) {
            // System.out.println(num);
            if (num % 3 != 0) {
                return false;
            }
            num /= 3;
        }
        return num == 1;
    }



    public static void main(String[] args) {
        int test = 9;
        System.out.println(isPowerOfThree(test));
        System.out.println(Math.cbrt(9.0));

    }
    
}

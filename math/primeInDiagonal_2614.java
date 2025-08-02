/*

    You are given a 0-indexed two-dimensional integer array nums.

    Return the largest prime number that lies on at least one of the 
    diagonals of nums. In case, no prime is present on any of the diagonals, return 0.

    Note that:

    An integer is prime if it is greater than 1 and has no positive integer divisors
    other than 1 and itself.
    An integer val is on one of the diagonals of nums if there exists an integer i 
    for which nums[i][i] = val or an i for which nums[i][nums.length - i - 1] = val.


    In the above diagram, one diagonal is [1,5,9] and another diagonal is [3,5,7].

    

    Example 1:

    Input: nums = [[1,2,3],[5,6,7],[9,10,11]]
    Output: 11
    Explanation: The numbers 1, 3, 6, 9, and 11 are the only numbers present on at least
    one of the diagonals. Since 11 is the largest prime, we return 11.
    Example 2:

    Input: nums = [[1,2,3],[5,17,7],[9,11,10]]
    Output: 17
    Explanation: The numbers 1, 3, 9, 10, and 17 are all present on at least one of the
    diagonals. 17 is the largest prime, so we return 17.
    

    Constraints:

    1 <= nums.length <= 300
    nums.length == numsi.length
    1 <= nums[i][j] <= 4*106
*/


public class primeInDiagonal_2614 {
    public boolean isPrime(int num) {
        int start = 2;

        if (num < start) return false;

        while (start <= Math.sqrt(num)) {
            if (num % start == 0) {
                return false;
            }
            start++;
        }
        return true;
    }
    public int diagonalPrime(int[][] nums) {
        /*
         * APPROACH: 
         * loop through each value in the matrix
         * at index i, i for the diagonals and i, 
         * n - 1 - i (n(length of nums)) for the antidiagonals
         * find all the prime number of the
         * diagonals and the anti diagonals with a function to calculate
         * the primes. 
         * Lastly find the largest prime number with the is prime
         * function
         */
        
        int n = nums.length;
        int largest = 0;

        // find the diagonals
        for (int i = 0; i < nums.length; i++) {
   
            if (isPrime(nums[i][i])) {
                // System.out.println("found prime!");
                // System.out.println("nums[i][i]: " + nums[i][i]);
                largest = Math.max(largest, nums[i][i]);
            }
            if (isPrime(nums[i][n - 1 - i])) {
                // System.out.println("found prime!");
                // System.out.println("nums[i][n - 1 - i]: " + nums[i][n - 1 - i]);
                largest = Math.max(largest, nums[i][n - 1 - i]);
            }

        }
        

        return largest;
        
    }
    
}

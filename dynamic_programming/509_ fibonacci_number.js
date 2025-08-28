/**
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, 
 * such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
 * F(0) = 0, F(1) = 1
 * F(n) = F(n - 1) + F(n - 2), for n > 1.
 * Given n, calculate F(n).
 * @param {number} n
 * @return {number}
 */
 var fib = function(n) {
    //  design a hashmap
    let fib_nums = new Object();
    fib_nums[0] = 0;
    fib_nums[1] = 1;

    for (let i = 2; i <= n; i++) {
        fib_nums[i] = fib_nums[i - 1] + fib_nums[i - 2];
    }

    return fib_nums[n];
 };

 let test = fib(10);
 console.log(test);
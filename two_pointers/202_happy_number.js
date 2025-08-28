/**
 * Write an algorithm to determine if a number n is happy.
 * A happy number is a number defined by the following process:
 *      Starting with any positive integer, replace the number by the sum of the squares of its digits.
 *      Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 *      Those numbers for which this process ends in 1 are happy.
 *      Return true if n is a happy number, and false if not.
 * @param {number} n
 * @return {boolean}
 */
 var isHappy = function(n) {
    let hash = new Map();
    while (n !== 1) {
        let current = findNext(n);
        if (hash.get(current) !== undefined) return false
        hash.set(current, n) 
        n = current;
        console.log(n);
    }
    console.log(hash.keys());
    return true;
};

function findNext(num) {
    let next = 0;
    while (num > 0) {
        let digit = num % 10;
        next += (digit * digit);
        num = Math.floor(num / 10);
    }
    return next;
}

// test 1
// console.log(isHappy(4));

// test 2
// console.log(isHappy(19));

// test 3
console.log(isHappy(5));
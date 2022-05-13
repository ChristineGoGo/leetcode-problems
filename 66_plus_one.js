/**
 * @param {number[]} digits
 * @return {number[]}
 * You are given a large integer represented as an integer array digits, 
 * where each digits[i] is the ith digit of the integer. The digits are ordered from most 
 * significant to least significant in left-to-right order. The large integer does not
 *  contain any leading 0's.increment the large integer by one and return the resulting array of digits.
 */
 var plusOne = function(digits) {

    // ------------------------------ APPROACH 1 (FASTER) -----------------------------
    //  digits[digits.length - 1];
    // for (let i = digits.length - 1; i > -1; i--) {
    //     if (digits[i] === 9) {
    //         digits[i] = 0;
    //     } else {
    //         digits[i] += 1;
    //         return digits;
    //     }
        
    // }

    // digits.unshift(1);
    // return digits;

    // ------------------------------ APPROACH 2 (VERY SLOW AND SOMETIMES NOT EVEN WORKS) -----------------------------
    return (BigInt(digits.join("")) + 1n).toString().split("").map(Number);

};

// console.log(plusOne([6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,5,4,3]));
console.log(plusOne([4, 3, 2, 9]));
/**
 * The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
 * For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
 * Given an integer num, return its complement.
 * @param {number} num
 * @return {number}
 *
 */

// ------------------------------------------------------------------------------------------------------
// -----------------------  APPROACH 1 ------------------------------------------------------------------
//  var findComplement = function(num) {
//     a = toBinary(decimal);
//     b = switchBinary(a);
//     return toDecimal(b);
// };

// function toBinary(decimal) {
//     let binary = [];
//     let temp = decimal;
    
//     while (temp > 0) {
//         binary.push(temp % 2);
//         temp = Math.trunc(temp / 2);
//     }
//     return binary.reverse();
// }

// function switchBinary(arr) {
//     for (let i = 0; i < arr.length; i++) {
//         arr[i] === 0 ? arr[i] = 1 : arr[i] = 0;
//     }
//     return arr;
// }

// function toDecimal(arr) {
//     let [sum, index] = [0, arr.length - 1];
//     for (let i = 0; i < arr.length; i++) {
//         sum += (Math.pow(2, index) * arr[i]);
//         index--;
//     }
//     return sum;
// }

// ------------------------------------------------------------------------------------------------------
// -----------------------  APPROACH 2 ------------------------------------------------------------------
 var findComplement = function(num) {
    let b = num.toString(2).split("");
    for (let i = 0; i < b.length; i++) {
        b[i] === '0' ? b[i] = '1' : b[i] = '0';
    }
    
    return parseInt(b.join(""), 2);
};

console.log(findComplement(5));

/* Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5. */

/**
 * @param {number} x
 * @return {number}
 */

//SOLUTION 1
//  let mySqrt = function(x) {
//     // 0 1 2...x
//     // pick a number whose square is equal/ smaller than x
//     // binary search

//     let i = 0;
//     let j = x;

//     // [i, middle, j], using Math.ceil
//     while (i < j ){
//         const middle = Math.ceil((i + j) / 2) // if i === j - 1, middle would be j
//         const square = middle ** 2
//         if (square === x) return middle
//         if (square < x) {
//             i = middle
//         } else {
//             j = middle - 1
//         }
//     }

//     return i
// };


// SOLUTION 2
 let mySqrt = function(x) {
    // 0 1 2...x
    // pick a number whose square is equal/ smaller than x
    // binary search

    if( x <= 1) return x

    let i = 0;
    let j = x;

    // [i, middle, j], using Math.floor
    while (i < j ){
        const middle = Math.floor((i + j) / 2) // if i === j - 1, middle would be j
        const square = middle ** 2
        if (square === x) return middle
        
        if (square < x) {
            i = middle + 1
        } else {
            j = middle
        }
    }

    return i - 1
};


console.log(mySqrt(12))
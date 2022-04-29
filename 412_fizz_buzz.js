/* 

    Given an integer n, return a string array answer (1-indexed) where:

    answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
    answer[i] == "Fizz" if i is divisible by 3.
    answer[i] == "Buzz" if i is divisible by 5.
    answer[i] == i (as a string) if none of the above conditions are true.

 */

/* 
    FOR EACH
    for ([initialization]; [condition]; [final-expression])
    statement
    
*/
 
/*
 * @param {number} n
 * @return {string[]}
 */
// -----------------------------------------------------------------------------------------------------------
// --------------------------------------- APPROACH 1 --------------------------------------------------------
// let fizzBuzz = function(n) {
//     let result = [];
//     for(let i =1; i < n + 1 ; i++){
//         if ((i % 3 === 0) && (i % 5 === 0 )){
//             result.push("FizzBuzz");
//         } else if (i % 3 === 0) {
//             result.push("Fizz")
//         } else if (i % 5 === 0) {
//             result.push("Buzz");
//         } else {
//             result.push(i.toString());
//         }
//     }
//     return result
// };

// // -----------------------------------------------------------------------------------------------------------
// // --------------------------------------- APPROACH 2 --------------------------------------------------------
// var fizzBuzz = function(n) {
//     let answer = [];
//     for (let i = 1; i <= n; i++) {
//         let divisible_by_3 = (i % 3 === 0);
//         let divisible_by_5 = (i % 5 === 0);
        
//         let strRslt = "";
        
//         if (divisible_by_3) strRslt += "Fizz";
//         if (divisible_by_5) strRslt += "Buzz";
//         if (strRslt === "") strRslt += i.toString();
        
//         answer.push(strRslt);
//     }
//     return answer;
// };

// -----------------------------------------------------------------------------------------------------------
// --------------------------------------- APPROACH 3 --------------------------------------------------------
var fizzBuzz = function(n) {
    let answer = [];
    let map = new Map();
    map.set(3, "Fizz");
    map.set(5, "Buzz");

    for (let i = 1; i <= n; i++) {
        let strAns = "";
        map.forEach((value, key) => { 
            if (i % key === 0) strAns += value;
        });

        if (strAns === "") strAns += i.toString();

        answer.push(strAns);
    }
    return answer;
};
console.log(fizzBuzz(15))

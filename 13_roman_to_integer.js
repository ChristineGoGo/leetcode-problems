/**
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000

  * For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

  * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

  *     I can be placed before V (5) and X (10) to make 4 and 9. 
  *     X can be placed before L (50) and C (100) to make 40 and 90. 
  *     C can be placed before D (500) and M (1000) to make 400 and 900.

  *  Given a roman numeral, convert it to an integer. 
 * @param {string} s
 * @return {number}
 */

// optimal solution
var romanToInt = function(s) {
    //create a mapping
    // I, V, X, L, C, D and M.
    //Symbol Value I 1 V 5 // X 10 // L 50 // C 100 // D 500 // M 1000

    const conversions = new Map();
    conversions.set('I', 1);
    conversions.set('V', 5);
    conversions.set('X', 10);
    conversions.set('L', 50);
    conversions.set('C', 100);
    conversions.set('D', 500);
    conversions.set('M', 1000);

    // declare total and i, total is where the total value is stored
    let total = 0;
    let i = 0;
    while (i < s.length) {
        // for each iteration compare the current character with the next
        // add integer value to the total if next character is less than current
        if ( (s.length - i > 1) && conversions.get(s[i]) < conversions.get(s[i + 1])) {
            curr = conversions.get(s[i + 1]) - conversions.get(s[i]);
            total += curr;
            i += 2;
        } else {
            total += conversions.get(s[i]);
            i++;
        }
    }
    return total;

};

// console.log(romanToInt("MCMXCIV"));
console.log(romanToInt("CXVII"));
// console.log(romanToInt("MCMXCIV"));

// my OVER simplified solution
// no need to create a new list we can just loop over the string
// the multiple if statements are uneccessary and only work for one scenario
// creating a mapping saves so many lines of code
// var romanToInt = function(s) {
//     let s_arr = s.split("");
//     let total = 0;
//     for(let i = s_arr.length; i >= 0 ; i--){
//         char = s_arr[i]
//         console.log(char);
//         if( char === 'I'){
//            total += 1;
//            } else if(char === 'V'){
//                      if(s_arr[i - 1] === 'I'){
//                          total += 4;
//                      } else {
//                         total += 5;
//                      }              
//                 console.log(total);
//             }else if(char === 'X'){
//                      if(s_arr[i - 1] === 'I'){
//                          total += 9;
//                      } else {
//                         total += 10;
//                      }
//                      console.log(total);
//             }else if(char === 'L'){
//                      if(s_arr[i - 1] === 'X'){
//                          total += 40;
//                      }else{total += 50;}
//                      console.log(total);
//             }else if(char === 'C'){
//                      if(s_arr[i - 1] === 'X'){
//                          total += 90;
//                      }else{total += 100;}
//                      console.log(total);
//             }else if(char === 'D'){
//                      if(s_arr[i - 1] === 'C'){
//                          total += 400;
//                      }else{total += 500;}
//                      console.log(total);
//             }else if(char === 'M'){
//                      if(s_arr[i - 1] === 'C'){
//                          total += 900;
//                      }else {total += 1000;}
//                      console.log(total); 
//             }
//     }
//     return total;
// };

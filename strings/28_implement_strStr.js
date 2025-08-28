/**
 * Implement strStr().

 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 * Clarification:

 * What should we return when needle is an empty string? This is a great question to ask during an interview.

 * For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
 var strStr = function(haystack, needle) {

    //
    let [hstart, hend, nstart] = [0, haystack.length - 1, 0];
    // return 0 for empty string
    if (!needle) {
        return 0 
    }
    // my long solution
    // while (hstart < hend) {
    //     console.log(hstart)
    //     // check if the first letter of haystack matches that of the needle
    //     if (haystack[hstart] !== needle[nstart]) {
    //         console.log(' haystack[hstart] and needle[nstart] are ' + (hstart, hend))

    //         hstart++;
    //     } else {
    //         // if the haystack letter matches that of needle,
    //         // compare the current haystack subtring  whith the needle and remove letters 
    //         // till you get a match 
    //         if (haystack.substring(hstart,hend) === needle) {
    //             return hstart
    //         }
    //         else{
    //             hend--;
    //         }
    //     }
    // }
    // return -1;

    //optimized solution
    let i = 0;
    while (haystack.substring(i, needle.length + i) !== needle && i <= haystack.length) {
        i ++;
    }
    return i > haystack.length? -1 : i;
};

//test 1 solution: 2
console.log(strStr("hello", "ll"))
//test 2 solution:
console.log(strStr("aaaaa", "bba"))
// test 3 solution: 0 
console.log(strStr("", ""))

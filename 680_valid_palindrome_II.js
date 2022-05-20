/**
 * Given a string s, return true if the s can be palindrome after deleting at most one character from it.
 * @param {string} s
 * @return {boolean}
 */
 var validPalindrome = function(s) {
    let [start, end] = [0, s.length-1];

    while (start < end) {
        if (s[start] === s[end]) {
            start ++;
            end--;
        } else {
            return isPalindrome(s.substring(start + 1, end + 1)) || isPalindrome(s.substring(start, end))
        }
    }
    return true;
    
};


/**
 * Given a string str, return true if the string is a palindrome
 * @param {string} str
 * @param {number} start
 *  @param {number} end
 * @return {boolean}
 */

function isPalindrome(str, start=0, end=str.length - 1) {
    while (start < end) {
        if (str[start] === str[end]) {
            start++;
            end--;
        } else {
            return false;
        }
    }
    return true;
}

// test 1 
// console.log(validPalindrome("abccbxa"));

// test 2
// console.log(validPalindrome("aba"));

// test 3 
// console.log(validPalindrome("a"));

// test 4 
// console.log(validPalindrome("bddb"));

// test 5 
console.log(validPalindrome("yd"));


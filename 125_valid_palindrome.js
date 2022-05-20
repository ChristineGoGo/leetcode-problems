/**
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
 * removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters
 * include letters and numbers.Given a string s, return true if it is a palindrome, or false otherwise.
 * @param {string} s
 * @return {boolean}
 */
 var isPalindrome = function(s) {
    //  this regex allows undescores as well
    // const regex = /\w/g;
    const regex = /[A-Za-z0-9]/g;
    let result = true;
    s = s.match(regex);
    const ns = s !== null ? s.join("").toLowerCase() : result = true;

    // console.log(ns);

    let [start, end] = [0, ns.length - 1];

    while (start < end) {
        if (ns[start] === ns[end]) {
            start++;
            end--;
        } else {
            result = false;
            return result;
        }
    }
    return result;
};
// test 1
console.log(isPalindrome("A man, a plan, a canal: Panama"));

// test 2
console.log(isPalindrome("race a car"));

// test 3
console.log(isPalindrome(" "));

// test 3
console.log(isPalindrome("racecar"));

// test 4
console.log(isPalindrome(".,"));

// test 4
console.log(isPalindrome("ab_a"));


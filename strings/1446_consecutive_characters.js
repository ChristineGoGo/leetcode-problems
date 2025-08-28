/**
 * The power of the string is the maximum length of a non-empty substring that contains only one unique character.
 * Given a string s, return the power of s.
 * @param {string} s
 * @return {number}
 */
 var maxPower = function(s) {
    let prev = "";
    let max = 0;
    let count = 0;

    for (let i = 0; i < s.length; i++) {
        if (s[i] === prev) {
            count++;
        } else {
            count = 1;
            prev = s[i];
        }
        max = Math.max(max, count);
    }

    return max;
};

// test1 expected 2
const test1 = maxPower("leetcode");
console.log(test1);

// test2 expected 5
const test2 = maxPower("abbcccddddeeeeedcba");
console.log(test2);

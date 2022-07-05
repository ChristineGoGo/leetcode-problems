/**
 * @param {string} s
 * @return {boolean}
 * Given a string s, check if it can be constructed by
 * taking a substring of it and appending multiple copies of the substring together.
 */

 var repeatedSubstringPattern = function(s) {
    let sub = "";
    l = s.length;

    for (let i = 1; i <= l / 2; i++) {
        sub = s.substring(0, i);
        if (l % i === 0) {
            sub = sub.repeat(l/i);
            if (sub === s) return true;
        }
    }
    return false;
};

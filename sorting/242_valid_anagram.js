/**
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
 *  typically using all the original letters exactly once.
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */

//  ----------------------------------------------------- APPROACH 1 --------------------------------
// var isAnagram = function (s, t) {
//     if (s.length !== t.length) return false;

//     let s_map = new Map();
//     let t_map = new Map();
    
//     for (let i = 97; i < (97 + 26); i++) {
//         s_map.set(String.fromCharCode(i), 0);        
//         t_map.set(String.fromCharCode(i), 0);        
//     }

//     for (let i = 0; i < t.length; i++) {
//         t_val = t_map.get(t[i]);
//         s_val = s_map.get(s[i]);

//         t_map.set(t[i], t_val + 1);
//         s_map.set(s[i], s_val + 1);
//     }

//     for (const [key, value] of s_map) {
//         if (value > 0 ) {
//             if (t_map.get(key) !== value) return false;
//         }
//     }
//     return true;
// };

//  ----------------------------------------------------- APPROACH 2 --------------------------------
var isAnagram = function (s, t) {
    function sortString(str) {
        return str.split("").sort().join("");
    }
    return sortString(s) === sortString(t);
};


// test1
console.log(isAnagram("g", "g"));


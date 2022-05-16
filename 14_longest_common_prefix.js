/* Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "". */

/**
 * @param {string[]} strs
 * @return {string}
 */
// ----------------------------------- APPROACH 1 ------------------------------------------------
//  var longestCommonPrefix = function(strs) {
//     let prefix = strs[0];
//     for (let i = 1; i < strs.length; i++) {
//         while(strs[i].indexOf(prefix) != 0) {
//             prefix = prefix.substring(0, prefix.length - 1);
//         }        
//     }
//     return prefix
// };

// ----------------------------------- APPROACH 2 ------------------------------------------------
var longestCommonPrefix = function(strs) {

    let prefix = strs[0];
    for (let j = 1; j < strs.length; j++) {
        while (prefix.length > 0) {
            if (strs[j].indexOf(prefix) === 0) break;
            prefix = prefix.slice(0, -1);
        }
    }
    return prefix;
}

// Test one
console.log(longestCommonPrefix(["flower", "flow", "flight"]));

// Test two
console.log(longestCommonPrefix(["dog", "racecar", "car"]));

// Test three 
console.log(longestCommonPrefix(["c","acc","ccc"]));

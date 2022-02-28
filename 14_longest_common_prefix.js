/* Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "". */

/**
 * @param {string[]} strs
 * @return {string}
 */
 var longestCommonPrefix = function(strs) {
    prefix = strs[0];
    for (let i = 1; i < strs.length; i++) {
        while(strs[i].indexOf(prefix) != 0) {
            prefix = prefix.substring(0, prefix.length - 1);
        }        
    }

    return prefix
    
};

// Test one
console.log(longestCommonPrefix(["flower", "flow", "flight"]));

// Test two
console.log(longestCommonPrefix(["dog","racecar","car"]));


// prefix = "flowe"
// prefix = prefix.substring(0, prefix.length - 1)
// console.log(prefix)
// console.log("flow".indexOf(prefix));
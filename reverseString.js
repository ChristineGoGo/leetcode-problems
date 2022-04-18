
/**
 * @param {string} s
 * @return {string}
 */
let reverseString = function(s) {
    let sb = "";
    let j = 0;

    for (let i = 0; i <= s.length; i++) {
        if (s[j] === ' ') {
            sb += s[j];
            j = i;
        } else if (s[j] !== ' ' && (s[i] === ' ' || i >= s.length)) {
            for (let k = i - 1; k >= j; k--) {
                sb += s[k];
            }
            j = i;
        }
    }    
    return sb;  
}

let sample = "Dog Dange";
console.log(reverseString(sample));
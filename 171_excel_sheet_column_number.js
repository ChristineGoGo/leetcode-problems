/** 
 * Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.
 * @param {string} columnTitle
 * @return {number}
 */
 var titleToNumber = function(columnTitle) {
    //  create a mapping for A - Z
    let chars = new Map;
    let charCode = 65;

    for (let i = 0; i < 26; i++) {
        chars.set(String.fromCharCode(charCode), i + 1);
        charCode ++;        
    }
    
    // start from left to right
    let column = 0;
    let position = 0;
    for (let i = columnTitle.length - 1; i >= 0; i--) {
        curr = chars.get(columnTitle[i]);
        column += (curr * Math.pow(26, position));
        position++; 
    }
    
    return column;
};

let result  = titleToNumber("AZZC");
console.log(result);

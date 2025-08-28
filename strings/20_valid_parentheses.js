/**
 *  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 *  determine if the input string is valid.An input string is valid if:
 *      Open brackets must be closed by the same type of brackets.
 *      Open brackets must be closed in the correct order.
 * @param {string} s
 * @return {boolean}
 */

//  ----------------------------- SOLUTION 1 FAILED TEST "{[]}" ------------------------------------------------
//  var isValid = function(s) {
//     let t = s.split("");
//      //create a map with keys being the open brackets
//     let parenthesis = new Map();
//     parenthesis.set("(", ")");
//     parenthesis.set("{", "}");
//     parenthesis.set("[", "]");
//      //loop over array matching the open brackets to closed ones
//     let i = 0;
//     while (i < t.length) {
//         if (t[i + 1] !== parenthesis.get(t[i])) return false;
//         t.splice(i + 1, 1);
//         i++;
//         console.log(t);
//     }
//     return true;
// };

// //  ----------------------------- SOLUTION 2 FAILED TEST "([)]" ------------------------------------------------
// var isValid = function(s) {
//     let t = s.split("");
//      //create a map with keys being the open brackets
//     let parenthesis = new Map();
//     parenthesis.set("(", ")");
//     parenthesis.set("{", "}");
//     parenthesis.set("[", "]");
//      //loop over array matching the open brackets to closed ones
//     let i = 0;
//     while (i < t.length) {
//         if (!t.includes(parenthesis.get(t[i]))) return false;
//         t.splice(t.indexOf(parenthesis.get(t[i])), 1);
//         i++;
//         // console.log(t);
//     }
//     return true;
// };

//  ----------------------------- SOLUTION 3 FAILED TEST "[({(())}[()])]" ------------------------------------------------
// var isValid = function(s) {
//     let t = s.split("");
//      //create a map with keys being the open brackets
//     let parenthesis = new Map();
//     parenthesis.set("(", ")");
//     parenthesis.set("{", "}");
//     parenthesis.set("[", "]");
//      //loop over array matching the open brackets to closed ones
//     let i = 0;
//     while (i < t.length) {
//         // if there are no closing brackets return false
//         if (!t.includes(parenthesis.get(t[i]))) return false;

//         // console.log(t[t.length - 1]);
//         // delete the closing brackets for each opening bracket in the correct order
//         if ((t[i + 1] === parenthesis.get(t[i])) || (t[t.length - 1] === parenthesis.get(t[i])) ) {
//             t.splice(t.indexOf(parenthesis.get(t[i])), 1);
//         }
//         i++;
//     console.log(`loop ${i}`);
//     console.log(t);
// }
// return true;
// };

//  ----------------------------- SOLUTION 3 JUST USING THE DANG STACK GAL!! ------------------------------------------------
var isValid = function(s) {
    //create a map with keys being the open brackets
    let parenthesis = new Map();
    parenthesis.set("(", ")");
    parenthesis.set("{", "}");
    parenthesis.set("[", "]");
    //create a stack to store the opening brackets
    let stack = [];
    for (let i = 0; i < s.length; i++) {
        if (parenthesis.get(s[i])) {
            // add opening brackets to the stack
            stack.push(s[i]);
        } else {
            // for closing brackets match them to the last opening bracket
            let open = stack[stack.length - 1];
            if (s[i] === parenthesis.get(open)) {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    // console.log(stack);
    return stack.length === 0;
};

// test1 expected true
const test1 = isValid("(){}[]");
console.log(test1);

// test2 expected false
const test2 = isValid("({}[]");
console.log(test2);

// test3 expected true
const test3 = isValid("{[]}");
console.log(test3);

// test4 expected false
const test4 = isValid("([)]");
console.log(test4);

// test5 expected true
const test5 = isValid("[({(())}[()])]");
console.log(test5);

// test6 expected false
const test6 = isValid(")(){}");
console.log(test6);

// test7 expected false
const test7 = isValid("[");
console.log(test7);


// Approach 1 not optimized

// function solution(A) {
//     let sorted_A = A.sort((a, b) => a - b);
//     let curr = Math.max(...A);
//     if (curr <= 0) {
//         return 1
//     } else {
//         for (let i = 1; i < sorted_A.length; i++) {
//             if(sorted_A.indexOf(i) === -1) return i;
//         }
//     }
//     return curr + 1;
// }

// Approach 2 with maps
function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)
    let m = new Map();
    for (let i = 0; i < A.length; i++){
        m.set(A[i],true);
    }

    for (let i = 1; i <= A.length; i++ ) {
        if (m.get(i) === undefined) return i;
    }

    return Math.max(...A) + 1;
}


// test1
let test1 = solution([1, 3, 6, 4, 1, 2]);
let test2 = solution([1,2, 3]);
let test3 = solution([-1, -3]);

console.log(test1);
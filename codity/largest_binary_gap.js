/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, 
  - number 9 has binary representation 1001 and contains a binary gap of length 2. 
  - The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. 
  - The number 20 has binary representation 10100 and contains one binary gap of length 1.
  - The number 15 has binary representation 1111 and has no binary gaps. 
  - The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

    function solution(N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..2,147,483,647].
*/

function solution(N) {
    let res = N.toString(2);
    let curr_gap = 0;
    let curr_one = 0;
    let next_one = 1;

    while (next_one < res.length && next_one !== -1) {
        next_one = res.indexOf("1", curr_one + 1);
        curr_gap = Math.max(((next_one - curr_one) -1), curr_gap);

        curr_one = next_one;
        
    }

    return curr_gap
};


let test1 = solution(9);
console.log(`result for 9 is: ${test1}`);

let test2 = solution(529);
console.log(`result for 529 is: ${test2}`);

let test3 = solution(20);
console.log(`result for 20 is: ${test3}`);

let test4 = solution(15);
console.log(`result for 15 is: ${test4}`);

let test5 = solution(32);
console.log(`result for 32 is: ${test5}`);

let test6 = solution(2147483647);
console.log(`result for 2,147,483,647 is: ${test6}`);




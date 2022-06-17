/**
 * In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
 * If the town judge exists, then:
 *    - The town judge trusts nobody.
 *    - Everybody (except for the town judge) trusts the town judge.
 *    - There is exactly one person that satisfies properties 1 and 2.
 * You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.
 * Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
 * @param {number} n
 * @param {number[][]} trust
 * @return {number}
 */
 var findJudge = function(n, trust) {
    const trusting_people = new Map();
    const people = new Array();
    trust.forEach(element => {
        if (trusting_people.get(element[1]) === undefined) {
            trusting_people.set(element[1], 0);
        }
        trusting_people.set(element[1], (trusting_people.get(element[1]) + 1));
        people.push(element[0]);
    });

    for (const [key, value] of trusting_people) {
        if ((value === n - 1) && !people.includes(key)) return key;
    }
    return -1;
};

// test1 expected result = 3
let test1 = findJudge(5, [[1,3], [2,3], [4,3], [4,1], [5,3], [5,1], [5,4]]);
console.log(test1);

// test2 expected result -1
let test2 = findJudge(5, [[2,1], [3,1], [4,2], [4,3], [4,5], [5,1]]);
console.log(test2);

// test3 expected result -1
let test3 = findJudge(5, [[1,4], [2,4], [3,2], [3,4], [4,2], [5,4]]);
console.log(test3);

// test4 expected result 1
let test4 = findJudge(1, []);
console.log(test4);

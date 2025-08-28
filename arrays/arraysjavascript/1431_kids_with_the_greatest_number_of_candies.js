/**
 * There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies,
 * denoting the number of extra candies that you have. Return a boolean array result of length n, where result[i] is true if,
 * after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.
 * Note that multiple kids can have the greatest number of candies.
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
 var kidsWithCandies = function(candies, extraCandies) {
    let result = [];
    let greatest = Math.max(...candies);

    for (let i = 0; i < candies.length; i++) {
        let current_greatest = candies[i] + extraCandies;
        if (current_greatest >= greatest) {
            result.push(true);
        } else {
            result.push(false);
        }
    }
    return result;
};

// test1 Expected Output: [true,true,true,false,true]
let test1 = kidsWithCandies(candies = [2,3,5,1,3], extraCandies = 3)
console.log(test1);

// test2 Expected Output: [true,false,false,false,false]
let test2 = kidsWithCandies(candies = [4,2,1,1,2], extraCandies = 1)
console.log(test2);

// test3 Expected Output: [true,false,true]
let test3 = kidsWithCandies(candies = [12,1,12], extraCandies = 10)
console.log(test3);

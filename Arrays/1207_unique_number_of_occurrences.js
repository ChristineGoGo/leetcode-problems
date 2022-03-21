/**
 * Given an array of integers arr, return true if the number of occurrences
 * of each value in the array is unique, or false otherwise.
 * @param {number[]} arr
 * @return {boolean}
 */
 var uniqueOccurrences = function(arr) {
    const counts = new Object();
    for (const num of arr) {
        if (counts[num] == undefined) counts[num] = 0;
        counts[num] ++;
    }
    let occurrences = Object.values(counts);
    return occurrences.length === new Set(occurrences).size;
};


var result = uniqueOccurrences([1, 2, 2, 1, 1, 3]);
console.log(result);
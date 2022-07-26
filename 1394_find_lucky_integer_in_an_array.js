/**
 * Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
 * Return the largest lucky integer in the array. If there is no lucky integer return -1.
 * @param {number[]} arr
 * @return {number}
 */
 var findLucky = function(arr) {
    let largest = 0;
    let m = new Map();
    
    for (let i = 0; i < arr.length; i++) {
        let curr = m.get(arr[i]);
        if (curr === undefined){
            m.set(arr[i], 1)   
        } else {
            m.set(arr[i], curr += 1 );
        }
    }
    
    for ([key, value] of m) {
        if (key === value) largest = Math.max(largest, key);
    }
    
    return largest === 0 ? -1 : largest;
};
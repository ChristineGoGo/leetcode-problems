/**
 * Let's call an array arr a mountain if the following properties hold:
 * arr.length >= 3
 * There exists some i with 0 < i < arr.length - 1 such that:
 *      arr[0] < arr[1] < ... arr[i-1] < arr[i]
 *      arr[i] > arr[i+1] > ... > arr[arr.length - 1]
 * Given an integer array arr that is guaranteed to be a mountain, 
 * return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
 * @param {number[]} arr
 * @return {number}
 */

let mountainPeak = function(arr) {
    // // solution 1, time complexity and space is low
    // for (let i = 0; i < arr.length; i++) {
    //     if (arr[i] > arr[i + 1]) return i;
    // }

    // solution 2 Binary Search
    let [start, end] = [0, arr.length - 1];

    while (start < end) {
        mid = Math.trunc((start + end)/ 2);
        if (arr[mid] < arr[mid + 1]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start;
}

let arr = [1, 2, 3, 4, 1];
console.log(mountainPeak(arr));
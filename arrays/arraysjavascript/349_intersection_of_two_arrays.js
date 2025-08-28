/**
 * Given two integer arrays nums1 and nums2, return an array of their intersection. 
 * Each element in the result must be unique and you may return the result in any order.
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
 function intersection(nums1, nums2){
    let result = [];
    set1 = new Set(nums1);
    set2 = new Set(nums2);
    for (item of set1){
        if (set2.has(item)) result.push(item);
    }
    return result;
}

// test1
console.log(intersection(nums1 = [1,2,2,1], nums2 = [2,2]));
// test1
console.log(intersection(nums1 = [4,9,5], nums2 = [9,4,9,8,4]));


// var intersection = function(nums1, nums2) {
//     let set1 = new Set(nums1);
//     let set2 = new Set(nums2);
    
// };

// const set1 = new Set();

// set1.add(1);
// set1.add('some text!');
// const o = {"a": 1, "b": 2}
// set1.add(o);
// set1.add({"a": 1, "b": 2});

// // for (let item of set1) console.log(item);
// // for (let item of set1.keys()) console.log(item);
// // for (let item of set1.values()) console.log(item);
// // for (let [key, value] of set1.entries()) console.log(key, value);

// const set2 = new Set([1,2,2,3,4]);
// // finding difference and intersections using filter
// const inter = new Set([...set1].filter(x => set2.has(x)));
// const diff = new Set([...set1].filter(x => !set2.has(x)));

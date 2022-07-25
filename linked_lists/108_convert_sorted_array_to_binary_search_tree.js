/**
 * Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
 * A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
 * @param {number[]} nums
 * @return {TreeNode}
 */
 var sortedArrayToBST = function(nums) {
    function helper(left, right){
        if (left > right) return null;
        
        let m = Math.floor((right - left) / 2) + left;
        
        const root = new TreeNode(nums[m]);
        
        root.left = helper(left, m - 1);
        root.right = helper(m + 1, right);
        
        return root;
    }
    
    return helper(0, nums.length - 1);
    
};


// Create a list node
function TreeNode(val,right, left) {
    this.val = (val === undefined ? 0 : val);
    this.right = (right === undefined ? null : right); 
    this.left  = (left === undefined ? null : left ); 
}
// test1
// expected
//        0
//       /  \
//     -3    9
//     / \  /  \
//   -10 n  5

// test1 = sortedArrayToBST(nums = [-10,-3,0,5,9]);
// console.log(test1);


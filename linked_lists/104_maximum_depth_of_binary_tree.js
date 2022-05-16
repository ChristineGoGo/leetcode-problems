/**
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 * @param {TreeNode} root
 * @return {number}
 */

// -------------------------------------------------------- SOLUTION 1 -----------------------------------------------------------------
// BREADTH FIRST SEARCH

// function maxDepth(root) {
//     if (root === null) return 0;
//     let queue = [root];
//     let height = 0;
//     while(queue.length) {
//         let n = queue.length;
//         height++;

//         for (let i = 0; i < n; i++) {
//             let current = queue.shift();
//             if (current.left !== null) queue.push(current.left);
//             if (current.right !== null) queue.push(current.right);
//         }
//     }

//     return height;
// }

// -------------------------------------------------------- SOLUTION 2 -----------------------------------------------------------------
// RECURSION
function maxDepth(root) {
    if (root == null) return 0;
    return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
}

function TreeNode(val, left=null, right=null) {
    this.val = val;
    this.left = left;
    this.right = right;
}


// testcase 1
let a = new TreeNode(3);
let b = new TreeNode(9);
let c = new TreeNode(20);
let d = new TreeNode(15);
let e = new TreeNode(17);

a.left = b;
a.right = c;
c.left = d;
c.right = e;
console.log(maxDepth(a));
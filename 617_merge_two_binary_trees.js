/**
 * You are given two binary trees root1 and root2.
 * Imagine that when you put one of them to cover the other, 
 * some nodes of the two trees are overlapped while the others are not. 
 * You need to merge the two trees into a new binary tree. The merge rule 
 * is that if two nodes overlap, then sum node values up as the new value of the merged node.
 *  Otherwise, the NOT null node will be used as the node of the new tree.
 * Return the merged tree.
 * Note: The merging process must start from the root nodes of both trees.
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {TreeNode}
 */

// ---------------------------------------- APPROACH : RECURSION ------------------------------------------
// var mergeTrees = function(root1, root2) {
//     if (root1 === null) return root2;
//     if (root2 === null) return root1;
//     root1.val = root1.val + root2.val;
//     root1.left = mergeTrees(root1.left, root2.left);
//     root1.right = mergeTrees(root1.right, root2.right);
//     return root1;
// };

// ---------------------------------------- APPROACH : ITERATION ------------------------------------------

var mergeTrees = function(root1, root2) {
    if (root1 === null ) return root2;
    let stack = [[root1, root2]];
    

    while (stack.length > 0) {
        let curr = stack.pop();
        
        if(curr[0] === null || curr[1] === null) continue;
        
        curr[0].val += curr[1].val;
                
        if (curr[0].left !== null ){
            stack.push([curr[0].left, curr[1].left])
        } else {
            curr[0].left = curr[1].left;
        }
        
        if (curr[0].right !== null ){
            stack.push([curr[0].right, curr[1].right])
        } else {
            curr[0].right = curr[1].right;
        }
        
    }
    return root1;
};

// Definition for a binary tree node.
function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val);
    this.left = (left===undefined ? null : left);
    this.right = (right===undefined ? null : right);
}

// root1
//          1
//        /   \
//      3      2
//    /  \    /  \
//   5     
const a = new TreeNode(1);
const b = new TreeNode(3);
const c = new TreeNode(2);
const d = new TreeNode(5);

a.right = c;
a.left = b;
b.left = d;

// root2
//          2
//        /   \
//      1      3
//    /  \    /  \
//        4       7     
const A = new TreeNode(2);
const B = new TreeNode(1);
const C = new TreeNode(3);
const D = new TreeNode(4);
const E = new TreeNode(7);

A.right = C;
A.left = B;
B.right = D;
C.right = E;

// test1
const test1 = mergeTrees(a, A);
console.log(test1);

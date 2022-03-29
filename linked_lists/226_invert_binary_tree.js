/**
 * Given the root of a binary tree, invert the tree, and return its root.
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */


function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (val === undefined ? 0 : left)
    this.right = (val === undefined ? 0 : right)
}

/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var invertTree = function(root) {
    //recursive
    if(!root){
        return root;
       }
    let tmp = root.left;
    root.left = root.right;
    root.right = tmp;

    invertTree(root.left);
    invertTree(root.right);

    return root;
};

a = new TreeNode('4');
b = new TreeNode('2');
c = new TreeNode('7');
d = new TreeNode('1');
e = new TreeNode('3');
f = new TreeNode('6');
g = new TreeNode('9');

a.right = c;
a.left = b;
b.right = e;
b.left = d;
c.right = g;
c.left = f;

console.log(printNode(a));

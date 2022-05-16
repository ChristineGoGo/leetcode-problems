/**
 * Given the root node of a binary search tree and two integers low and high,
 *  return the sum of values of all nodes with a value in the inclusive range [low, high].
 * @param {TreeNode} root
 * @param {number} low
 * @param {number} high
 * @return {number}
 */


 var rangeSumBST = function(root, low, high) {

    // approach 3 recursion optimized to to take advantage of BST properties
    if (root === null) return 0;
    let sum = 0;

    // root value is within the range specified
    if (root.val >= low && root.val <= high) sum = root.val;

    // values to the left subtree keep getting lower
    if (root.val >= low || root.val >= high) {
        sum += rangeSumBST(root.left, low, high);
    }

    // values to the right subtree keep getting higher
    if (root.val <= high || root.val <= low) {
        sum += rangeSumBST(root.right, low, high);
    }

    
    //------------------------------------------------------------------------------------------

    // approach 2 recursion on all nodes
    // let sum = 0;
    // helper(root);
    // function helper(node) {
    //     if (node.val >= low && node.val <= high) sum += node.val;
    //     if (node.left) helper(node.left);
    //     if (node.right) helper(node.right);
    // }

    //------------------------------------------------------------------------------------------

    // approach 1, traversing all nodes DFS
    // let [sum, queue] = [0, []];
    // queue.push(root);

    // while (queue.length) {
    //     current = queue.pop();
    //     if (current.val >= low && current.val <= high) {
    //         sum += current.val;
    //     }
    //     if (current.left !== null) queue.push(current.left);
    //     if (current.right !== null) queue.push(current.right);
    // }
    //------------------------------------------------------------------------------------------

    return sum;
};

/**
 * A binary search tree has the following characteristics:
 *      the left subtree of a node contains only nodes with keys lesser than the node's key
 *      the right subtree contains only nodes with keys greater than the node's key
 *      left and right subtrees must also be a binary search tree
 * 
 * @param {*} val 
 * @param {*} left 
 * @param {*} right 
 */
function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

// test1
a = new TreeNode(10);
b = new TreeNode(5);
c = new TreeNode(15);
d = new TreeNode(3);
e = new TreeNode(7);
f = new TreeNode(18);

a.left = b;
a.right = c;
b.left = d;
b.right = e;
c.right = f;

console.log(rangeSumBST(a, 7, 15));





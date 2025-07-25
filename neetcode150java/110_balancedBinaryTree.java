// package neetcode;

/*
 * Given a binary tree, determine if it is height balanced
 */

 /**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int[] dfs(TreeNode root){
            if (root == null) return new int[] {1, 0};

            int[] right = dfs(root.right);
            int[] left = dfs(root.left);

            boolean balanced = (Math.abs(right[1] - left[1]) <= 1) && left[0] == 1 && right[0] == 1;
            int[] result = new int[]{balanced? 1 :0 , 1 + Math.max(left[1], right[1])};
            return result;
    }
    public boolean isBalanced(TreeNode root) {
        return dfs(root)[0] == 1;
    }
}



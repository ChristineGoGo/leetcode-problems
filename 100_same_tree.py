"""
    Given the roots of two binary trees p and q, write a function to check if they are the same or not.

    Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # ------ APPROACH 1 - ITERATIVE
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        stack = [(p, q)]

        while len(stack) > 0:
            current = stack.pop()

            if current[0] == None and current[1] == None: continue
            if current[0] == None or current[1] == None: return False

            if current[0] != None and current[1] != None:
                if current[0].val != current[1].val: return False

            stack.append((current[0].right, current[1].right))
            stack.append((current[0].left, current[1].left))

        return True

    # ------ APPROACH 2 - RECURSION

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p == None and q == None: return True
        if (p == None and q != None) or (p != None and q == None): return False

        if (p != None and q != None):
            if p.val == q.val:
                return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
            else:
                return False

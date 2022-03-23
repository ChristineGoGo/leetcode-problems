"""
    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
"""

# Definition for a binary tree node.

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
        
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.isMirror(root.left, root.right)
    
    def isMirror(self, a, b):
        if a == None and b == None:
            return True
        if a != None and b!= None:
            return (a.val == b.val) and self.isMirror(a.left, b.right) and self.isMirror(a.right, b.left)
        
   


if __name__ == '__main__':
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(2)
    d = TreeNode(3)
    e = TreeNode(4)
    f = TreeNode(4)
    g = TreeNode(3)

    ##           1
    ##        /     \
    ##       2       2
    ##      / \     / \
    ##    3   4     4   3
    ## Output: True
    
    a.left = b
    a.right = c 
    b.left = d
    b.right = e
    c.left = f
    c.right = g
    
    s = Solution()
    print(s.isSymmetric(a))
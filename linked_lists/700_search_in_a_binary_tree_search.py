"""
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
This is using the in-order
"""
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
        
class Solution:
    # non recursively
    def searchBST(self, root):
        stack = []
                
        while root or stack:
            if root:
                stack.append(root)
                root = root.left
            else:
                root = stack.pop()
                print(root.val)    
                root = root.right

            
          
                
                
            
                        
                    
    
if __name__ == '__main__':
    a = TreeNode('A')
    b = TreeNode('B')
    c = TreeNode('C')
    d = TreeNode('D')
    e = TreeNode('E')
    f = TreeNode('F')
    g = TreeNode('G')
    h = TreeNode('H')
    i = TreeNode('I')
    
##          F
##         /  \
##        B     G
##      /   \    \
##     A     D     I
##          /  \   /
##         C    E  H
##

    f.right = g
    f.left = b
    b.left = a
    b.right = d
    d.right = e
    d.left = c
    g.right = i
    i.left = h
    
    s = Solution()
    print(s.searchBST(f))


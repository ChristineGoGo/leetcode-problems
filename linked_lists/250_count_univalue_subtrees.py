"""

Given the root of a binary tree, return the number of uni-value subtrees.

A uni-value subtree means all nodes of the subtree have the same value.

"""
# Definition for a binary tree node.

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        

count = 0    
def countUnivalSubtrees(root):
    """
    :type root: TreeNode
    :rtype: int
    """
    global count
    if root == None: return 0
    
    lefts = countUnivalSubtrees(root.left)  
    rights = countUnivalSubtrees(root.right)
    
    return lefts, rights




if __name__ == '__main__':
    a = TreeNode(5)
    b = TreeNode(1)
    c = TreeNode(5)
    d = TreeNode(5)
    e = TreeNode(5)
    f = TreeNode(5)

    
##          5
##         /  \
##        1     5
##       / \      \
##      5   5       5                                        
    
    a.left = b
    a.right = c
    b.left = d
    b.right = e
    c.right = f
    
    print(countUnivalSubtrees(a))
    
    
    
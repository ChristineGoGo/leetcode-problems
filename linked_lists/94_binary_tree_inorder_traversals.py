"""
Given the root of a binary tree, return the preorder traversal of its nodes' values.
"""
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
        
class Solution:
    # non recursively
    # def inorderTraversal(self, root):
    #     stack = []
    #     current = root
    #     results = []
        
    #     while stack or current:
    #         if current:
    #            stack.append(current)
    #            current = current.left
    #         else:
    #             current = stack.pop()
    #             results.append(current.val)
    #             current = current.right
    
    # recursively
    def inorderTraversal(self, root, answer):
        if root == None: return
        self.inorderTraversal(root.left, answer) ## traverse the left subtree  
        answer.append(root.val) ## visit the root
        self.inorderTraversal(root.right, answer) ## traverse the right subtree 
        
    def iot(self, root):
        answer = []
        self.inorderTraversal(root, answer)
        return answer
        
        
            
            
            
                    
    
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
    print(s.iot(b))


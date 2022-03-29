"""
Given the root of a binary tree, return the preorder traversal of its nodes' values.
"""
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
        
class Solution:
    # # non recursively
    # def preorderTraversal(self, root):
    #     if root == None: return
    #     stack = [root]
    #     result = []
        
    #     while len(stack) > 0:
    #         current = stack.pop()
    #         result.append(current.val)
            
            
    #         if current.right: stack.append(current.right)
    #         if current.left: stack.append(current.left)
            
    #     return result
    
    # recursively
    def preorderTraversal(self, root, answer):
        if root == None: return
        
        answer.append(root.val) ## visit the root
        self.preorderTraversal(root.left, answer) ## traverse the left subtree        
        self.preorderTraversal(root.right, answer) ## traverse the right subtree  
        

    def pod(self, root):
        answer = []
        self.preorderTraversal(root, answer)
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
    print(s.pod(b))


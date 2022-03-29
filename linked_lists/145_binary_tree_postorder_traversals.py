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
    # def postorderTraversal(self, root):
    #     stack_one = []    
    #     stack_two = []
    #     result = []
       
    #     stack_one.append(root)
       
    #     while len(stack_one) > 0:
    #         current = stack_one.pop()
    #         stack_two.append(current)

    #         if current.left: stack_one.append(current.left)   
    #         if current.right: stack_one.append(current.right)

    #     for i in range(len(stack_two)):
    #         result.append(stack_two.pop().val)
            
    #     return result
    
    # recursively
    def postorderTraversal(self, root, answer):
        if root == None: return 
        self.postorderTraversal(root.left, answer) ## traverse the left subtree             
        self.postorderTraversal(root.right, answer)   ## traverse the right subtree 
        answer.append(root.val)
    
    def postorder(self, root):
        answer = []
        self.postorderTraversal(root,answer)
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
    print(s.postorder(b))


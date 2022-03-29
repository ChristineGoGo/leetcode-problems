"""
Given the root of a binary tree and an integer targetSum, 
return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

"""




# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
        
# class Solution(object):
#     def hasPathSum(self, root, targetSum):
#         """
#         :type root: TreeNode
#         :type targetSum: int
#         :rtype: bool
#         """


# my solution that only works on the left nodes
# i just needed to use a set to store the current running sum and node together in the stack
# def has_path_sum(root, targetSum):
#     if root == None: return False

#     stack = []
#     count = 0
#     stack.append(root)
    
#     while len(stack) > 0:
#         current = stack.pop()
        
#         # reset count if you start looping the right side
#         if current == root.right:
#             count = root.val
            
#         count += current.val
        
#         if current.left == None and current.right == None:
#             if count == targetSum:
#                 return True
#             else:
#                 count -= current.val
#         if current.right: stack.append(current.right)    
#         if current.left: stack.append(current.left)
    
#     return False

# correct solution using pre-order  traversal
# def has_path_sum(root, targetSum):
#     if root == None: return False

#     stack = []
#     current = root
#     count = root.val
#     stack.append((count, root))
    
#     while len(stack) > 0:
#         count, current = stack.pop()
        
#         # check if leaf node
#         if current.left == None and current.right == None and count == targetSum:
#                 return True
    
#         if current.right: stack.append((count + current.right.val, current.right))    
#         if current.left: stack.append((count + current.left.val, current.left))
    
#     return False


# recursion solution
def has_path_sum(root, targetSum):
    if root == None: return False
    if root.left == None and root.right == None and targetSum == root.val:
        return True
    
    return has_path_sum(root.left,targetSum - root.val) or has_path_sum(root.right, targetSum - root.val)
    
    



                


if __name__ == '__main__':
    a = TreeNode(5)
    b = TreeNode(4)
    c = TreeNode(8)
    d = TreeNode(11)
    e = TreeNode(13)
    f = TreeNode(4)
    g = TreeNode(7)
    h = TreeNode(2)
    i = TreeNode(1)
    
##          5
##         /  \
##        4     8
##       /     /  \
##      11    13   4   
##     /  \         \
##    7    2         1 
## output targetSum = 22 True 
    
    a.left = b
    a.right = c
    b.left = d
    d.left = g
    d.right = h
    c.left = e
    c.right = f
    f.right = i
    
    print(has_path_sum(a,22))
 ########################################################################################################################################################
 
    #  TEST TWO  
    # a = TreeNode(1)
    # b = TreeNode(-2)
    # c = TreeNode(-3)
    # d = TreeNode(1)
    # e = TreeNode(3)
    # f = TreeNode(-2)
    # g = TreeNode(-1)
    

##           1
##         /  \
##       -2    -3
##      /  \   /  
##     1    3 -2   
##    /           
##  -1  

    # a.left = b
    # a.right = c
    # b.left = d
    # b.right = e
    # d.left = g
    # c.left = f            
 
    

    # s = Solution()
    # print(has_path_sum(a,22))
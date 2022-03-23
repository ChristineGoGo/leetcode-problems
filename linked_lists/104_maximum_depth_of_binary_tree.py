"""

Given the root of a binary tree, return its maximum depth
A binary tree's maximum depth is the number of nodes along 
the longest path from the root down to the farthest leaf node

Use the top down solution for recursion, similar to preorder

"Top-down" means that in each recursive call, we will visit the node first to come up with some values, 
and pass these values to its children when calling the function recursively. So the "top-down" solution can be considered 
as a kind of preorder traversal. To be specific, the recursive function top_down(root, params) works like this:


1. return specific value for null node
2. update the answer if needed                      // answer <-- params
3. left_ans = top_down(root.left, left_params)      // left_params <-- root.val, params
4. right_ans = top_down(root.right, right_params)   // right_params <-- root.val, params
5. return the answer if needed                      // answer <-- left_ans, right_ans


In this case:
1. return if root is null
2. if root is a leaf node:
3.     answer = max(answer, depth)         // update the answer if needed
4. maximum_depth(root.left, depth + 1)     // call the function recursively for left child
5. maximum_depth(root.right, depth + 1)    // call the function recursively for right child

"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        

## my naive  and verbose solution
## did not consider that a root may have both left and right nodes hmmmm............
## the other two functions are not needed, only one 
# def max_depth_left(root, lefts):
#     if root == None: return
#     lefts.append(root.val)
#     max_depth_left(root.left, lefts)
    
# def max_depth_right(root, rights):
#     if root == None: return
    
#     rights.append(root.val)
#     max_depth_right(root.right, rights)


# def results(root):
#     lefts = []
#     rights = []
#     max_depth_left(root, lefts)
#     max_depth_right(root, rights)
#     return max(len(lefts), len(rights))


# # optimized shorter code

# class Solution(object):
#     def maxDepth(self, root):
#         """
#         :type root: TreeNode
#         :rtype: int
#         """
#         if root == None: return 0
#         lefts = self.maxDepth(root.left)
#         rights = self.maxDepth(root.right)
        
#         return max(lefts, rights) + 1

# Another solution
answer = 0
  
def max_depth(root, depth):
    """
    :type root: TreeNode
    :rtype: int
    """
    
    global answer
    
    if root == None: return
    if root.left == None and root.right == None:
        answer = max(depth, answer)
    
    max_depth(root.left, depth + 1)
    max_depth(root.right,  depth + 1)

def call_max_depth(root):
    depth = 1
    max_depth(root, depth)
    
    return answer
        
        
        


    
    


if __name__ == '__main__':
    
    a = TreeNode('A')
    b = TreeNode('B')
    c = TreeNode('C')
    d = TreeNode('D')
    e = TreeNode('E')
    f = TreeNode('F')
    g = TreeNode('G')

    # # ##           E
    # # ##         /   \
    # # ##        B     F
    # # ##       / \   / \
    # # ##      A   D     G
    # # ##         /
    # # ##        C
    # # ## Output: 4
    
    e.left = b
    e.right = f
    b.left = a
    b.right = d
    d.left = c
    f.right = g
    
    # s = Solution()
    print(call_max_depth(e))
    
    
    
    
    
    # a = TreeNode(3)
    # b = TreeNode(9)
    # c = TreeNode(20)
    # d = TreeNode(15)
    # e = TreeNode(7)

    # # # ##           3
    # # # ##          /  \
    # # # ##         9    20
    # # # ##              / \
    # # # ##             15   7
    # # # ## Output: 3
    
    # a.left = b
    # a.right = c
    # c.left = d
    # c.right = e
    
    # s = Solution()
    # print(s.call_max_depth(a))
    
    
    # a = TreeNode(8)
    # b = TreeNode(-6)
    # c = TreeNode(7)
    # d = TreeNode(6)
    # e = TreeNode(4)

    # # ##           8
    # # ##          /  \
    # # ##         -6   7
    # # ##         /
    # # ##        6 
    # # ##         \
    # # ##          4
    # # ## Output: 4
    
    # a.left = b
    # a.right = c
    # b.left = d
    # d.right = e
    
    # s = Solution()
    # print(s.maxDepth(a))
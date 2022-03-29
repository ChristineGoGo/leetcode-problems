"""
    Given the root of a binary tree, return the level order traversal of its nodes' values. 
    (i.e., from left to right, level by level).
"""
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution(object):
    # non recursively
    # my solution,Solution One
    # def levelOrder(self, root):
    #     """
    #     :type root: TreeNode
    #     :rtype: List[List[int]]
    #     """
        
    #     if root == None: return 
        
    #     queue = []
    #     level = []
    #     level_result = []
    #     results = []
    #     queue.append(root)
        
        
    #     while len(queue) > 0:
            
    #         # level is used to hold all items in the current level           
    #         for i in queue:
    #             level.append(i)
            
    #         # clear the queue to make room for items in the next level
    #         queue = []
            
    #         # for item in level:
    #         #     if item.right and item.left:
    #         #         queue.insert(0,item.right)
    #         #         queue.insert(0, item.left)
    #         #     else:
    #         #         if item.right: queue.append(item.right)
    #         #         if item.left: queue.append(item.left)
            
    #         # add items to queue
    #         for item in level:
    #             if item.left: queue.append(item.left)
    #             if item.right: queue.append(item.right)
    
            
    #         for i in level:
    #             level_result.append(i.val)
            
    #         results.append(level_result)
    #         level_result = []
    #         level = []

    #     return results
    
    
    ##############################################################################################
    
    ## print all the nodes in one level from left to right
    
    def print_level(root, level);
        if root is None: return
        print(root.left, root.val, root.right)
    
        
 
if __name__ == '__main__':
    a = TreeNode(3)
    b = TreeNode(9)
    c = TreeNode(20)
    d = TreeNode(15)
    e = TreeNode(7)

    # ##           3
    # ##          /  \
    # ##         9    20
    # ##              / \
    # ##             15   7
    # ## Output: [[3],[9,20],[15,7]]
    
    a.left = b
    a.right = c
    c.left = d
    c.right = e

    
    # a = TreeNode(1)
    # b = TreeNode(2)
    # c = TreeNode(3)
    # d = TreeNode(4)
    # e = TreeNode(5)
    
     ##           1
    ##          /  \
    ##         2    3
    ##        /      \
    ##       4        5
    ## Output: [[1],[2,3],[4,5]]
    
    # a.left = b
    # a.right = c
    # b.left = d
    # c.right = e
    
    # a = TreeNode(0)
    # b = TreeNode(2)
    # c = TreeNode(4)
    # d = TreeNode(1)
    # e = TreeNode(3)
    # f = TreeNode(-1)
    # g = TreeNode(5)
    # h = TreeNode(1)
    # i = TreeNode(6)
    # j = TreeNode(8)
    

    ##            0
    ##          /  \
    ##         2     4
    ##        /     / \
    ##       1     3  -1
    ##      /  \    \   \
    ##     5    1    6    8
    
    # a.right = c
    # a.left = b
    # b.left = d
    # c.left = e
    # c.right = f
    # d.right = h
    # d.left = g
    # e.right = i
    # f.right = j
    
    
    ## Output: [[0],[2,4],[1,3,-1], [5,1,6,8]]
    
    # a = TreeNode('a')
    # b = TreeNode('b')
    # c = TreeNode('c')
    # d = TreeNode('d')
    # e = TreeNode('e')
    # f = TreeNode('f')
    # g = TreeNode('g')
    # h = TreeNode('h')
    # i = TreeNode('i')
    
    # ##            F
    # ##          /  \
    # ##         B     G
    # ##        / \     \
    # ##       A   D     I
    # ##          / \   /
    # ##         C   E  H
    
    # f.right = g
    # f.left = b
    # b.right = d
    # b.left = a
    # g.right = i
    # d.right = e
    # d.left = c
    # i.left = h
    

    s = Solution()
    print(s.levelOrder(a))
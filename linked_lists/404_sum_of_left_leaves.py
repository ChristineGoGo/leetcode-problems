"""Given the root of a binary tree, return the sum of all the left leaves"""
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        
class Solution:        
    def sum_of_left_leaves(self,root):
        
        self.sum = 0
        
        def depth_first_search(root):
            # Base case 1: None roots
            if root == None: return 0
            
            # Base case 2: check for leaf nodes
            if root.left:
                if root.left.left == None and root.left.right == None:
                    self.sum += root.left.val
            depth_first_search(root.left)            
            depth_first_search(root.right)            
    
        
        depth_first_search(root)
        return self.sum
    
        
if __name__ == '__main__':
    
    ## test 00
    root = Node(3)
    root.left = Node(9)
    root.right = Node(20)
    root.right.right = Node(7)
    root.right.left = Node(15)
    
    # ##              3
    # ##            /   \ 
    # ##          9      20
    # ##                /  \
    # ##                15   7
    s = Solution()
    
    print(s.sum_of_left_leaves(root))
    
    ## test 01
    # root = Node(1)
    # root.left = Node(3)
    # root.left.left = Node(2)
    # root.left.right = Node(8)
    # root.left.right.left = Node(10)
    # root.right = Node(4)
    # root.right.right = Node(7)
    # root.right.left = Node(5)
    
    ##               1
    ##            /     \ 
    ##          3        4
    ##         / \      /  \
    ##        2    8    5   7
    ##            /  
    ##           10
    # assert max_root_to_leaf(root) == 20
    
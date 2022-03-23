"""

You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.

"""
import math
import sys



class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        




# class Solution:
#     def sum_root_to_leaf_binary(self, root):
#         pass 

# PROBLEM: find the different paths of the root to leaf
def path_root_to_leaf(root):
    # base case 1
    if root == None: return 0
    # base case 2 check if we are at leaf node
    if root.left ==  None and root.right == None: return root.val
    
    return [root.val,ma] 

if __name__ == '__main__':
    
    ## test 00
    root = Node(5)
    root.left = Node(11)
    root.left.left = Node(4)
    root.left.right = Node(2)
    root.right = Node(3)
    root.right.right = Node(1)
    
    ##              5
    ##            /   \ 
    ##          11      3
    ##         /  \      \
    ##        4    2      1  
    
    
    # assert max_root_to_leaf(root) == 20
    print(max_root_to_leaf(root))


# PROBLEM: find the maximum root to leaf sum
## Solution One: depth-first

# def max_root_to_leaf(root):
#     # base case 1
#     if root == None: return -sys.maxsize
#     # base case 2 check if we are at leaf node
#     if root.left ==  None and root.right == None: return root.val
    
#     return max(max_root_to_leaf(root.left), max_root_to_leaf(root.right)) + root.val

# if __name__ == '__main__':
    
#     ## test 00
#     root = Node(5)
#     root.left = Node(11)
#     root.left.left = Node(4)
#     root.left.right = Node(2)
#     root.right = Node(3)
#     root.right.right = Node(1)
    
#     ##              5
#     ##            /   \ 
#     ##          11      3
#     ##         /  \      \
#     ##        4    2      1  
    
    
#     # assert max_root_to_leaf(root) == 20
#     print(max_root_to_leaf(root))





# PROBLEM: find the minimum value in the tree

## Solution Two: depth-first recursion
# def treeMin(root):
#     if root == None: return sys.maxsize
#     return min(root.val, treeMin(root.left), treeMin(root.right))

## Solution two breadth-first
# def treeMin(root):
#     if root == None: return sys.maxsize
    
#     queue = [root]
#     min_node = sys.maxsize
    
#     while len(queue) > 0:
#         current = queue.pop()
#         if current.val < min_node: min_node = current.val
        
#         if current.left: queue.insert(0, current.left)
#         if current.right: queue.insert(0, current.right)
    
    # return min_node
        
    

# if __name__ == '__main__':
    
    # ## test 00
    # root = Node(5)
    # root.left = Node(11)
    # root.left.left = Node(4)
    # root.left.right = Node(15)
    # root.right = Node(3)
    # root.right.right = Node(12)
    
    # ##              5
    # ##            /   \ 
    # ##          11      3
    # ##         /  \      \
    # ##        4    15     12  
    
    # assert treeMin(root) == 3
    
    # # ## test 01
    # root = Node(1)
    # root.left = Node(6)
    # root.left.left = Node(3)
    # root.left.right = Node(-6)
    # root.left.right.left = Node(2) 
    # root.right = Node(0)
    # root.right.right = Node(2)
    # root.right.right.right = Node(2)
    
    # # ##              1
    # # ##            /   \ 
    # # ##          6      0
    # # ##         /  \      \
    # # ##        3    -6     2
    # # ##             /       \
    # # ##            2         2
    
    
    # assert treeMin(root) == -6
    
    # ## test 02
    # root = Node(3)
    # root.left = Node(11)
   
    
    # # ##              3
    # # ##            /  
    # # ##          11      
    
    
    # assert treeMin(root) == 3


# PROBLEM: compute the total sum of the values in the tree

## Solution two recursion
# def treeSum(root):
#     if root == None: return 0
#     # rightValues = treeSum(root.right)        
#     return treeSum(root.left) + treeSum(root.right) + root.val

## Solution one
# def treeSum(root):
#     if root == None: return []
#     stack = [root]
#     count = 0
    
#     while len(stack) > 0:
#         current = stack.pop()
#         count += current.val
        
#         if current.left is not None:
#             stack.append(current.left)
#         if current.right is not None: 
#             stack.append(current.right)
            
#     return count

# if __name__ == '__main__':
    
#     ## test 00
#     root = Node(3)
#     root.left = Node(11)
#     root.left.left = Node(4)
#     root.left.right = Node(-2)
#     root.right = Node(4)
#     root.right.right = Node(1)
    
#     ##              3
#     ##            /   \ 
#     ##          11      4
#     ##         /  \      \
#     ##        4    -2     1  
    
    
#     assert treeSum(root) == 21
    
#     ## test 01
#     root = Node(1)
#     root.left = Node(6)
#     root.left.left = Node(3)
#     root.left.right = Node(-6)
#     root.left.right.left = Node(2) 
#     root.right = Node(0)
#     root.right.right = Node(2)
#     root.right.right.right = Node(2)
    
#     ##              1
#     ##            /   \ 
#     ##          6      0
#     ##         /  \      \
#     ##        3    -6     2
#     ##             /       \
#     ##            2         2
    
    
#     assert treeSum(root) == 10
    
#     ## test 02
#     root = Node(3)
#     root.left = Node(11)
   
    
#     ##              3
#     ##            /  
#     ##          11      
    
    
#     assert treeSum(root) == 14
    
        

    
    
 
# PROBLEM: return true if a target exists in a binary tree and false otherwise

## Solution two with recursion, depth first since
## it is not recommended to perform recursion with breadth first
# def treeIncludes(root, target):
#     if root == None: return False
#     # is root the target? base case
#     if root.val == target: return True
#     # is the target one of the root children? (false or true == true)
#     return treeIncludes(root.left, target) or treeIncludes(root.right, target) 
    
    
# if __name__ == '__main__':    
    ##test case 00
    
    # a = Node('a')
    # b = Node('b')
    # c = Node('c')
    # d = Node('d')
    # e = Node('e')
    # f = Node('f')
  

    # a.left = b
    # a.right = c
    # b.left = d
    # b.right = e
    # c.right = f
    
    # ##      a
    # ##     /  \
    # ##    b     c
    # ##  /   \    \
    # ## d    e     f

    # print(treeIncludes(a, 'e'))
    
    
    # ## test case 01
    # a = Node('a')
    # b = Node('b')
    # c = Node('c')
    # d = Node('d')
    # e = Node('e')
    # f = Node('f')
  

    # a.left = b
    # a.right = c
    # b.left = d
    # b.right = e
    # c.right = f
    
    # ##      a
    # ##     /  \
    # ##    b     c
    # ##  /   \    \
    # ## d    e     f

    # print(treeIncludes(a, 'a'))
    
    
    ## test case 02
    # a = Node('a')
    # b = Node('b')
    # c = Node('c')
    # d = Node('d')
    # e = Node('e')
    # f = Node('f')


    # a.left = b
    # a.right = c
    # b.left = d
    # b.right = e
    # c.right = f

    # ##      a
    # ##     /  \
    # ##    b     c
    # ##  /   \    \
    # ## d    e     f

    # print(treeIncludes(a, 'n'))
    
    
    ## test case 03
    # a = Node('a')
    # b = Node('b')
    # c = Node('c')
    # d = Node('d')
    # e = Node('e')
    # f = Node('f')
    # g = Node('g')
    # h = Node('h')
  

    # a.left = b
    # a.right = c
    # b.left = d
    # b.right = e
    # c.right = f
    # e.left = g
    # f.right = h

    
    # ##      a
    # ##     /  \
    # ##    b     c
    # ##  /   \    \
    # ## d     e     f
    # ##       /      \ 
    # ##      g         h      
    # print(treeIncludes(a, 'h')) 
    
    ## test case 04
    # a = Node('a')
    # b = Node('b')
    # c = Node('c')
    # d = Node('d')
    # e = Node('e')
    # f = Node('f')
    # g = Node('g')
    # h = Node('h')
  

    # a.left = b
    # a.right = c
    # b.left = d
    # b.right = e
    # c.right = f
    # e.left = g
    # f.right = h

    
    # ##      a
    # ##     /  \
    # ##    b     c
    # ##  /   \    \
    # ## d     e     f
    # ##       /      \ 
    # ##      g         h      
    
    # print(treeIncludes(a, 'p'))
    
    ## test case 05
    # print(treeIncludes(None, 'p')) 
    
    
    
     
 
## solution one with the breadth first version without recursion
# def treeIncludes(root, target):
#     if root == None: return False
#     queue = [root]
    
#     while len(queue) > 0:
#         current = queue.pop()
#         if current.val == target: return True
        
#         if current.left: queue.insert(0, current.left)
        
#         if current.right: queue.insert(0, current.right)
    
#     return False
    
# if __name__ == '__main__':    
    # test case 00
    
    # a = Node('a')
    # b = Node('b')
    # c = Node('c')
    # d = Node('d')
    # e = Node('e')
    # f = Node('f')
  

    # a.left = b
    # a.right = c
    # b.left = d
    # b.right = e
    # c.right = f
    
    # ##      a
    # ##     /  \
    # ##    b     c
    # ##  /   \    \
    # ## d    e     f

    # print(treeIncludes(a, 'e')) 
    
    
    # # # test case 01
    # a = Node('a')
    # b = Node('b')
    # c = Node('c')
    # d = Node('d')
    # e = Node('e')
    # f = Node('f')
  

    # a.left = b
    # a.right = c
    # b.left = d
    # b.right = e
    # c.right = f
    
    # ##      a
    # ##     /  \
    # ##    b     c
    # ##  /   \    \
    # ## d    e     f

    # print(treeIncludes(a, 'a')) 
    
    
    # # # test case 02
    # a = Node('a')
    # b = Node('b')
    # c = Node('c')
    # d = Node('d')
    # e = Node('e')
    # f = Node('f')
  

    # a.left = b
    # a.right = c
    # b.left = d
    # b.right = e
    # c.right = f
    
    # ##      a
    # ##     /  \
    # ##    b     c
    # ##  /   \    \
    # ## d    e     f

    # print(treeIncludes(a, 'n'))
    
    ## test case 03
    
    # a = Node('a')
    # b = Node('b')
    # c = Node('c')
    # d = Node('d')
    # e = Node('e')
    # f = Node('f')
    # g = Node('g')
    # h = Node('h')
  

    # a.left = b
    # a.right = c
    # b.left = d
    # b.right = e
    # c.right = f
    # e.left = g
    # f.right = h

    
    # ##      a
    # ##     /  \
    # ##    b     c
    # ##  /   \    \
    # ## d     e     f
    # ##       /      \ 
    # ##      g         h      
    # print(treeIncludes(a, 'h')) 
    
    
    # ## test case 04
    # a = Node('a')
    # b = Node('b')
    # c = Node('c')
    # d = Node('d')
    # e = Node('e')
    # f = Node('f')
    # g = Node('g')
    # h = Node('h')
  

    # a.left = b
    # a.right = c
    # b.left = d
    # b.right = e
    # c.right = f
    # e.left = g
    # f.right = h

    
    # ##      a
    # ##     /  \
    # ##    b     c
    # ##  /   \    \
    # ## d     e     f
    # ##       /      \ 
    # ##      g         h      
    # print(treeIncludes(a, 'p')) 
    
    ## test case 05
    # print(treeIncludes(None, 'p')) 
    






## bredth firth traversal uses a queue vs a stack
## the order is from horizontal insted of vertical like the 
## depth first

# def BreadthFirstValues(root):
    
#     # when given None values
#     if root == None: return [] 
#     queue = [root]
#     values = []
    
#     while len(queue) > 0:
#         # add from one end and remove from the other end
#         # use pop to remover last element
#         current = queue.pop()
#         values += current.val
        
#         if current.left is not None:
#             # use insert to add to the beginning
#             queue.insert(0, current.left)
            
#         if current.right is not None:
#             # use insert to add to the beginning
#             queue.insert(0, current.right)
            
#     return values
    
        




# if __name__ == '__main__':    
#     print("Following is the Bredth-First Search")
    # # test case 00
    
    # a = Node('a')
    # b = Node('b')
    # c = Node('c')
    # d = Node('d')
    # e = Node('e')
    # f = Node('f')
  

    # a.left = b
    # a.right = c
    # b.left = d
    # b.right = e
    # c.right = f
    
    # print(BreadthFirstValues(a)) 
    
    
    # test case 01
    
    # a = Node('a')
    # b = Node('b')
    # c = Node('c')
    # d = Node('d')
    # e = Node('e')
    # f = Node('f')
    # g = Node('g')
    # h = Node('h')

    # a.left = b
    # a.right = c
    # b.left = d
    # b.right = e
    # c.right = f
    # e.left = g
    # f.right = h
    
    # print(BreadthFirstValues(a)) 
    
    
    
    
    # test case 02
    
    # a = Node('a')
    
    # print(BreadthFirstValues(a))
    
    
    # test case 03
    
    # a = Node('a')
    # b = Node('b')
    # c = Node('c')
    # d = Node('d')
    # e = Node('e')
    # x = Node('x')
   

    # a.right = b
    # b.left = c
    # c.right = d
    # c.left = x
    # d.right = e
    
    # print(BreadthFirstValues(a)) 
    
    
    # test case 04
    
    # a = None
    
    # print(BreadthFirstValues(a)) 
   
   
    
    
    
  


## Solution One without recursion
# def depthFirstValues(root):
    
#     if root == None: return [] 
        
#     result = []
#     stack = [root]
#     while len(stack) > 0:
#         current = stack.pop()
#         result += current.val
        
#         if current.right != None:
#             stack.append(current.right)  
#         if current.left != None:
#             stack.append(current.left)
    
#     return result


# ## Solution two with recursion
# def depthFirstValues(root):
#     if root == None: return []
#     leftValues = depthFirstValues(root.left)
#     rightValues = depthFirstValues(root.right)

    
#     return[root.val, *leftValues, *rightValues]
      
     
    
        
        
        
        
# if __name__ == '__main__':    
#     print("Following is the Depth-First Search")
#     # test case 00
    
#     a = Node('a')
#     b = Node('b')
#     c = Node('c')
#     d = Node('d')
#     e = Node('e')
#     f = Node('f')
  

#     a.left = b
#     a.right = c
#     b.left = d
#     b.right = e
#     c.right = f
    
#     print(depthFirstValues(a)) 
    
    
    # test case 01
    
    # a = Node('a')
    # b = Node('b')
    # c = Node('c')
    # d = Node('d')
    # e = Node('e')
    # f = Node('f')
    # g = Node('g')

    # a.left = b
    # a.right = c
    # b.left = d
    # b.right = e
    # c.right = f
    # e.left = g
    
    
    
    # test case 03
    
    # a = Node('a')
    # b = Node('b')
    # c = Node('c')
    # d = Node('d')
    # e = Node('e')
    
    # a.right = b
    # b.left = c
    # c.right = d
    # d.right = e
         
     
    
       
    
    
  
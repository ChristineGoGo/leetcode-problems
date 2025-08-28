"""
    Given the roots of two binary trees root and subRoot,
    return true if there is a subtree of root with the same
    structure and node values of subRoot and false otherwise.

    A subtree of a binary tree tree is a tree that consists of
    a node in tree and all of this node's descendants. The
    tree tree could also be considered as a subtree of itself.
"""
class TreeNode:
    def __init__(self, val=0,left=None,right=None):
        self.val = val
        self.left = left
        self.right = right

def checkNodes(n1, n2):
    # if n1 and n2:
        # print(f"n1.val:{n1.val}, n2.val: {n2.val}")
    if not n1:
        return not n2
    if not n2:
        return not n1
    if n1.val != n2.val:
        # print("False")
        return False
    if not checkNodes(n1.left, n2.left):
        return False
    if not checkNodes(n1.right, n2.right):
        return False
    return True

def isSubtree(root, subRoot):
    stack = [root]
    while stack:
        curr = stack.pop()
        # print(f"curr.val: {curr.val}")
        if curr.val == subRoot.val:
            if checkNodes(curr, subRoot):
                return True
        if curr.left: stack.append(curr.left)
        if curr.right: stack.append(curr.right)
    return False



#       3
#     /   \
#    4     5
#   / \
#  1   2
a = TreeNode(3)
b = TreeNode(4)
c = TreeNode(5)
d = TreeNode(1)
e = TreeNode(2)

a.left = b
a.right = c
b.left = d
b.right = e

#       4
#     /  \
#    1    2

f = TreeNode(4)
g = TreeNode(1)
h = TreeNode(2)
f.left = g
f.right = h

print(f"checkNodes(a, f): {isSubtree(a, f)}") # True
# print(f"loopNode(a): {loopNode(f)}")

#            3
#          /   \
#         4     5
#        / \   / \
#       1   2
#          /
#         0
# tree
a = TreeNode(3)
b = TreeNode(4)
c = TreeNode(5)
d = TreeNode(1)
e = TreeNode(2)
f = TreeNode(0)
a.left = b
a.right = c
b.left = d
b.right = e
e.left = f

#        4
#      /  \
#     1    2
# sub tree
g =TreeNode(4)
h =TreeNode(1)
i =TreeNode(2)
g.left = h
g.right = i


print(f"isSubtree(a, g): {isSubtree(a, g)} ") # False

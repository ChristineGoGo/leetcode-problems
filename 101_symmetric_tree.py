"""
    Given the root of a binary tree, check whether it is a
    mirror of itself (i.e., symmetric around its center).
"""
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right= right

# # APPROACH 1 USING STACK
# def isSymmetric(root):
#     stack = [[root.left, root.right]]

#     while len(stack) > 0:
#         current = stack.pop()
#         if current[0] == None and current[1] == None:
#             continue

#         if (current[0] == None or current[1] == None ) or (current[0].val != current[1].val):
#             return False


#         stack.append([current[0].left, current[1].right])
#         stack.append([current[0].right, current[1].left])

#     return True

# APPROACH 2 USING RECURSIVELY
def isSymmetric(root):
    def checkMirror(l, r):
        if l == None and r == None:
            return True

        if l == None or r == None:
            return False

        return (l.val == r.val) and checkMirror(l.left, r.right) and checkMirror(l.right, r.left)


    return checkMirror(root, root)





# tests
#        1
#     /    \
#    2      2
#   /  \   /  \
#  3    4 4    3

a = TreeNode(1)
b = TreeNode(2)
c = TreeNode(2)
d = TreeNode(3)
e = TreeNode(4)
f = TreeNode(4)
g = TreeNode(3)

a.right = b
a.left = c
b.right = d
b.left = e
c.right = f
c.left = g
print(f'isSymmetric(a): {isSymmetric(a)} ') #True


# #        1
# #     /    \
# #    2      2
# #   /  \   /  \
# #       3      3

# a = TreeNode(1)
# b = TreeNode(2)
# c = TreeNode(2)
# d = TreeNode(3)
# e = TreeNode(3)

# a.right = b
# a.left = c
# b.right = d
# c.right = e

#        1
#     /    \
#    2      3


# a = TreeNode(1)
# b = TreeNode(2)
# c = TreeNode(3)

# a.right = b
# a.left = c




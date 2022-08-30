"""
    Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p
    and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant
    of itself).”
"""
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # APPROACH 1 - DEPTH FIRST SEARCH
    # def lowestCommonAncestor(self, root, p, q):
    #     if root == None: return
    #     stack = [root]

    #     while len(stack) > 0:
    #         c = stack.pop()
    #         if c.val < p.val and c.val < q.val:
    #             stack.append(c.right)
    #         elif c.val > p.val and c.val > q.val:
    #             stack.append(c.left)
    #         else:
    #             return c

    # APPROACH 1 - RECURSION
    def lowestCommonAncestor(self, root, p, q):
        if root.val < p and root.val < q:
            return self.lowestCommonAncestor(root.right, p, q)
        elif root.val > p and root.val > q:
            return self.lowestCommonAncestor(root.left, p, q)
        else:
            return root.val

# test1
#                6
#              /   \
#             /     \
#            /       \
#           2         8
#          / \       / \
#         /   \     /   \
#        0     4   7     9
#              /\
#             /  \
#            3    5


a = TreeNode(6)
b = TreeNode(2)
c = TreeNode(8)
d = TreeNode(0)
e = TreeNode(4)
f = TreeNode(7)
g = TreeNode(9)
h = TreeNode(3)
i = TreeNode(5)



a.left = b
a.right = c
b.left = d
b.right = e
c.left = f
c.right = g
e.left = h
e.right = i

# test2
#                2
#              /
#             /
#            /
#           1


# a = TreeNode(2)
# b = TreeNode(1)
# a.left = b

# test3
#                2
#                 \
#                  \
#                   \
#                    3


# a = TreeNode(2)
# b = TreeNode(3)
# a.right = b

result = Solution()
# print(f'result.lowestCommonAncestor(a, 2, 3): {result.lowestCommonAncestor(a, 2, 3)}') #2
# print(f'result.lowestCommonAncestor(a, 2, 1): {result.lowestCommonAncestor(a, 2, 1)}') #2
print(f'result.lowestCommonAncestor(a, 2, 4): {result.lowestCommonAncestor(a, 2, 4)}') #2
print(f'result.lowestCommonAncestor(a, 2, 8): {result.lowestCommonAncestor(a, 2, 8)}') #6
print(f'result.lowestCommonAncestor(a, 0, 5): {result.lowestCommonAncestor(a, 0, 5)}') #2
# print(f'result.lowestCommonAncestor(a, 3, 5): {result.lowestCommonAncestor(a, 3, 5)}') #4
# print(f'result.lowestCommonAncestor(a, 3, 5): {result.lowestCommonAncestor(a, 3, 5)}') #4



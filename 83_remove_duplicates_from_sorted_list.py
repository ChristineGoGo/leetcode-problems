"""
    Given the head of a sorted linked list, delete all duplicates such
    that each element appears only once. Return the linked list sorted as well.
"""
class TreeNode:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next

def deleteTreeNodes(head):
    current = head
    while current.next != None:
        if current.val == current.next.val:
            current.next = current.next.next
        else:
            current = current.next

a = TreeNode(1)
b = TreeNode(2)
c = TreeNode(3)
d = TreeNode(3)

a.next = b
b.next = c
c.next = d

deleteTreeNodes(a)

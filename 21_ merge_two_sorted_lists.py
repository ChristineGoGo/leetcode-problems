"""
    You are given the heads of two sorted linked lists list1 and list2.

    Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

    Return the head of the merged linked list.
"""

class ListNode:
    def __init__(self, val=0, next = None):
        self.val = val
        self.next = next


def loopOver(l):
    while l != None:
        print(l.val)
        l = l.next

# head = ListNode()
class Solution:
    def mergeTwoLists(self, list1, list2):

        if list1 == None: return list2
        if list2 == None: return list1

        head = ListNode()
        # print(list1.val, list2.val)

        if list1.val <= list2.val:
            head = list1
            list1 = list1.next
        else:
            head = list2
            list2 = list2.next

        head.next = self.mergeTwoLists(list1, list2)
        return head

a = ListNode(1)
b = ListNode(2)
c = ListNode(4)

d = ListNode(1)
e = ListNode(3)
f = ListNode(4)

a.next = b
b.next = c

d.next = e
e.next = f

list1 = a
list2 = d
# print(f'mergeTwoLists(list1, list2): {mergeTwoLists(list1, list2)} ')

test1 = Solution()
test1.mergeTwoLists(list1, list2)




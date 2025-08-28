"""
    You are given two non-empty linked lists representing two non-negative integers.
    The digits are stored in reverse order, and each of their nodes contains a single
    digit. Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number
    0 itself.
"""
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# APPROACH 1: SIMPLE BUT LENGTHY
# def addTwoNumbers(l1, l2):
#     head = ListNode()
#     c = head
#     while l1 != None or l2 != None:
#         if l1 and not l2:
#             total = l1.val
#         elif not l1 and l2:
#             total = l2.val
#         else:
#             total = (l1.val + l2.val)

#         to_add = total if total < 10 else total - 10
#         c.next = ListNode(to_add)
#         rem = total // 10 if total >= 10 else 0

#         if rem >= 1:
#             if l1 and l1.next:
#                 l1.next.val += rem
#             elif l2 and l2.next:
#                 l2.next.val += rem

#         curr_total = to_add
#         # print(f"curr_total: {curr_total}")
#         l1 = None if not l1 else l1.next
#         l2 = None if not l2 else l2.next
#         c = c.next
#     # print(f" rem:{rem}, c.val:{c.val}")
#     if rem >= 1: c.next = ListNode(rem)
#     return head.next

# APPROACH 2: COMPACT AND SOPHISTICATED
def addTwoNumbers(l1, l2):
    head = ListNode()
    c = head
    rem = 0
    while l1 != None or l2 != None:
        x = 0 if not l1 else l1.val
        y = 0 if not l2 else l2.val
        total = x + y + rem
        to_add = total % 10

        c.next = ListNode(to_add)
        rem = total // 10

        l1 = None if not l1 else l1.next
        l2 = None if not l2 else l2.next
        c = c.next
    if rem >= 1: c.next = ListNode(rem)
    return head.next





def createNodes(l, head=ListNode()):
    c = head
    for i in range(len(l)):
        c.next= ListNode(l[i])
        c = c.next

    return head.next.val

def loopNodes(head):
    while head != None:
        print(head.val)
        head = head.next

# tests
# 2 --> 4 --> 3
a = ListNode(2)
b = ListNode(4)
c = ListNode(3)
a.next = b
b.next  = c

# 5 --> 6 --> 4
d = ListNode(5)
e = ListNode(6)
f = ListNode(4)
d.next = e
e.next  = f

# [0]
g = ListNode()
h = ListNode()

# 9 --> 9 --> 9 --> 9 --> 9 --> 9 --> 9
i = ListNode(9)
j = ListNode(9)
k = ListNode(9)
l = ListNode(9)
m = ListNode(9)
n = ListNode(9)
o = ListNode(9)

i.next = j
j.next = k
k.next = l
l.next = m
m.next = n
n.next = o


# 9 --> 9 --> 9 --> 9
p = ListNode(9)
q = ListNode(9)
r = ListNode(9)
s = ListNode(9)

p.next = q
q.next = r
r.next = s

# print(f"addTwoNumbers:{addTwoNumbers(a, d)}")# [7, 0, 8]
# print(f"addTwoNumbers:{addTwoNumbers(g, h)}")# [0]
# print(f"addTwoNumbers:{addTwoNumbers(g, h)}")# [0]
# print(f"addTwoNumbers:{addTwoNumbers(i, p)}")# [8, 9, 9, 9, 0, 0, 0, 1]

print(f" Looping through nodes: {loopNodes(addTwoNumbers(i, p))}")

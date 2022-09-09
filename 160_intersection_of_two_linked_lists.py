"""
    Given the heads of two singly linked-lists headA and headB, return the node at which
    the two lists intersect. If the two linked lists have no intersection at all, return null.

    For example, the following two linked lists begin to intersect at node C1:
        A1 ---> A2 --->
                           ---->  C1 ---> C2
        B1 ---> B2 --->
    The test cases are generated such that there are no cycles anywhere in the entire linked structure.

    Note that the linked lists must retain their original structure after the function returns.

    Custom Judge:

    The inputs to the judge are given as follows (your program is not given these inputs):

        intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
        listA - The first linked list.
        listB - The second linked list.
        skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
        skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.

    The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program.
    If you correctly return the intersected node, then your solution will be accepted.
"""

def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        curr_A = headA
        curr_B = headB
        store_B = set()

    # APPROACH 1 BRUTE FORCE
#         while(curr_A != None):
#             while(curr_B != None):
#                 if curr_B == curr_A: return curr_B
#                 curr_B = curr_B.next
#             curr_A = curr_A.next
#             curr_B = headB

#     APPROACH 2 USING A SET TO STORE headB
#         while curr_B != None:
#             store_B.add(curr_B)
#             curr_B = curr_B.next

#         while curr_A != None:
#             if curr_A in store_B: return curr_A
#             curr_A = curr_A.next

#         return None


#     APPROACH 3 TWO POINTERS
        while curr_A != curr_B:
            curr_A = headB if curr_A == None else curr_A.next
            curr_B = headA if curr_B == None else curr_B.next

        return curr_A



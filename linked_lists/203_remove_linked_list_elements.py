"""
    Given the head of a linked list and an integer val,
    remove all the nodes of the linked list that has
    Node.val == val, and return the new head.
"""
def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
    if head == None: return head
    n = ListNode(0)
    n.next = head

    prev = n
    curr = n.next

    while curr != None:
        if curr.val == val:
            prev.next = curr.next
            curr = prev.next if prev != None else None
        else:
            prev = prev.next
            curr = curr.next

    return n.next

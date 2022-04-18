class ListNode:
    def __init__(self, val=0, next=None):
        """constructor to initiate this object"""

        # store data
        self.val = val

        # store reference (next item)
        self.next = next
        return

    def has_value(self, value):
        """method to compare the value with the node data"""
        if self.val == value:
            return True
        else:
            return False


class Solution:
    def __init__(self):
        """constructor to initiate the object"""
        self.head = None
        self.tail = None
        return

    def add_list_item(self, item):
        if not isinstance(item, ListNode):
            item = ListNode(item)
        if self.head is None:
            self.head = item
            return
        for current_node in self:
            pass
        current_node.next = item

    def list_length(self):
        count = 0
        current_node = self.head
        while current_node is not None:
            count += 1
            current_node = current_node.next

        return count


if __name__ == '__main__':
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(3)
    node4 = ListNode(4)
    node5 = ListNode(5)

    solution = Solution()

    for current_item in [node1, node2, node3, node4, node5]:
        solution.add_list_item(current_item)

    print(solution.list_length())

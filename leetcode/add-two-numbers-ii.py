# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def getTail(self, node: ListNode) -> ListNode:
        node.prev = None
        while node.next:
            prev = node
            node = node.next
            node.prev = prev
        
        return node

    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l1 = self.getTail(l1)
        l2 = self.getTail(l2)

        c = 0
        nodes = []
        while l1 or l2 or c:
            if l1:
                x = l1.val
                l1 = l1.prev
            else:
                x = 0
            if l2:
                y = l2.val
                l2 = l2.prev
            else:
                y = 0
            z = (x + y + c) % 10
            c = (x + y + c) // 10
            nodes.append(ListNode(z, None))

        if (c > 0):
            nodes.append(ListNode(c, None))
        p = None
        
        for n in nodes:
            if not p:
                p = n
            else:
                n.next = p
                p = n
        
        return nodes[-1]

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        c = 0
        vals = []
        while l1 or l2 or c:
            x, y = 0, 0
            if l1:
                x = l1.val
                l1 = l1.next
            if l2:
                y = l2.val
                l2 = l2.next
            
            vals.append((x+y+c) % 10)
            c = (x+y+c) // 10


        prev = None
        for v in vals[::-1]:
            prev = ListNode(v, prev)

        return prev

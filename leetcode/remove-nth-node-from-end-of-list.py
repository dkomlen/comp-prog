# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        pairs = {}
        prev = None
        nxt = head.next
        i = 1
        while nxt:
            pairs[i] = (prev, nxt)
            prev = prev.next if prev else head
            nxt = nxt.next if nxt else None
            i += 1

        pairs[i] = (prev, nxt)
        
        node = pairs[i - n + 1]
        if not node[0]:
            return node[1]
        node[0].next = node[1]
        return head

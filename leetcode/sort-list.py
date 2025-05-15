# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def merge(self, a: Optional[ListNode], b: Optional[ListNode]):
        ret = cur = None
        if not a:
            return b
        if not b:
            return a
        
        while a or b:
            if b is None or (a is not None and a.val <= b.val):
                min = a
                a = a.next
            else:
                min = b
                b = b.next
                
            if ret is None:
                ret = cur = min
            else:
                cur.next = min
                cur = cur.next
        
        return ret

    def split(self, head: ListNode):
        if not head or head.next is None:
            return head
        left_beg = left_end = head
        
        i = j = 0
        while head:
            if j > 2 * i + 1:
                left_end = left_end.next
                i += 1
            head = head.next
            j += 1
        
        right = left_end.next
        left_end.next = None
        return self.merge(self.split(left_beg), self.split(right))
    

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        
        return self.split(head)
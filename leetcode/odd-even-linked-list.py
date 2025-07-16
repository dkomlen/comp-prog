# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def copyNode(sefl, node: Optional[ListNode]):
        if not node:
            return node

        return ListNode(node.val, None)

    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        odd = True
        even_list = None
        ret = None
        cur_odd = ret
        cur_even = even_list


        while head:
            if not odd:
                if not even_list:
                    even_list = self.copyNode(head)
                    cur_even = even_list
                else:
                    cur_even.next = self.copyNode(head)
                    cur_even = cur_even.next
            else:
                if not ret:
                    ret = self.copyNode(head)
                    cur_odd = ret
                else:  
                    cur_odd.next = self.copyNode(head)
                    cur_odd = cur_odd.next

            odd = not odd
            head = head.next
        
        if cur_odd:
            cur_odd.next = even_list
        return ret
        
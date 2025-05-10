# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        cur = ret = None

        while list1 or list2:
            if list1:
                if list2:
                    if list1.val < list2.val:
                        val = list1.val
                        list1 = list1.next
                    else:
                        val = list2.val
                        list2 = list2.next
                else:
                    val = list1.val
                    list1 = list1.next
            elif list2:
                val = list2.val
                list2 = list2.next
            
            if cur is None:
                cur = ret = ListNode(val, None)
            else:
                cur.next = ListNode(val, None)
                cur = cur.next
            
        return ret
from collections import deque
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        queue = deque([root])
        i = 0
        while queue:
            elem = queue.pop()
            if elem is None:
                continue
            if type(elem) is TreeNode:
                queue.append(elem.right)
                queue.append(elem.val)
                queue.append(elem.left)
            else:
                # elem is value
                i +=1
                if i == k:
                    return elem

from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        ret = 0
        q = deque([])
        if root:
            q.append((root, 0, True))

        while q:
            (node, path_len, is_next_right) = q.popleft()
            
            ret = max(ret, path_len)
            if node.left:
                if is_next_right:
                    q.append((node.left, 1, True))
                else:
                    q.append((node.left, path_len + 1, True))
            if node.right:
                if is_next_right:
                    q.append((node.right, path_len + 1, False))
                else:
                    q.append((node.right, 1, False))


        return ret
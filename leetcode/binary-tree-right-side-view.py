# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []

        max_level = 0
        sol = []
        nodes = deque([(1, root)])
        while nodes:
            (level, node) = nodes.popleft()
            if level > max_level:
                sol.append(node.val)
                max_level += 1
            if node.right:
                nodes.append((level + 1, node.right))
            if node.left:
                nodes.append((level + 1, node.left))
        
        return sol

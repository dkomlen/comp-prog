# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        # traversal =  right, left, parent
        if root is None:
            return []

        nodes = [(root, True), (root.right, False), (root.left, False)]# [(node, expanded)]
        traversal = []

        while nodes:
            (node, expanded) = nodes.pop()
            if node is None:
                continue
            if expanded:
                traversal.append(node.val)
            else:
                nodes.append((node, True))
                nodes.append((node.right, False))
                nodes.append((node.left, False))

        return traversal

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque


class Solution:

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True

        dfs = deque([root])
        last = None
        while dfs:
            node = dfs.pop()
            if isinstance(node, TreeNode):
                if node.right:
                    dfs.append(node.right)
                dfs.append(node.val)
                if node.left:
                    dfs.append(node.left)
            else:
                if last is None:
                    last = node
                elif last >= node:
                    return False
                else:
                    last = node

        return True

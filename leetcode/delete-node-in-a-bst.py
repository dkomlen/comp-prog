# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def mergeTrees(self, left: Optional[TreeNode], right: Optional[TreeNode]) -> Optional[TreeNode]:
        if not left:
            return right
        if not right:
            return left
        
        p = left
        while p.right:
            p = p.right
        p.right = right
        return left

    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root:
            return None

        node = None
        current = root

        while current:
            parent = current
            if current.val == key:
                node = current
                break
            elif current.val < key:
                current = current.right
                if current:
                    current.right_parent = parent
            else:
                current = current.left
                if current:
                    current.left_parent = parent
            
        if node:
            tree = self.mergeTrees(node.left, node.right)
            if hasattr(node, 'left_parent'):
                node.left_parent.left = tree
            elif hasattr(node, 'right_parent'):
                node.right_parent.right = tree
            else:
                return tree
        
        return root
        

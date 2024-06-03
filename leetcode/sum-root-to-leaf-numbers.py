# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        ret = []
        q = [(root, 0)]
        while(q):
            x = q.pop()
            prefix = 10 * x[1] + x[0].val
            if (x[0].left == None and x[0].right == None):
                ret.append(prefix)
            if (x[0].left != None):
                q.append((x[0].left, prefix))
            if (x[0].right != None):
                q.append((x[0].right, prefix))

        return sum(ret)

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None

        nodes = {}
        visited = set()
        dfs = [node]
        while dfs:
            cur_node = dfs.pop()
            visited.add(cur_node.val)
            nodes[cur_node.val] = Node(val = cur_node.val, neighbors = [])
            dfs.extend([n for n in cur_node.neighbors if not n.val in visited])
        
        visited = set()
        dfs = [node]
        while dfs:
            cur_node = dfs.pop()
            visited.add(cur_node.val)
            new_node = nodes[cur_node.val]
            new_node.neighbors = [nodes[n.val] for n in cur_node.neighbors]
            dfs.extend([n for n in cur_node.neighbors if not n.val in visited])

        return nodes[node.val]
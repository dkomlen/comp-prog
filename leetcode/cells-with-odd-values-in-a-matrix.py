from typing import List


class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        mat = [[0]*m for _ in range(n)]
        for [r, c] in indices:
            mat[r] = [x + 1 for x in mat[r]]
            for row in mat:
                row[c] = row[c] + 1
        return sum([x % 2 for row in mat for x in row])

class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0

        n, m = len(grid), len(grid[0])
        total = 0

        for i in range(n):
            for j in range(m):
                total += min(max(grid[i]), max([row[j] for row in grid])) - grid[i][j]

        return total
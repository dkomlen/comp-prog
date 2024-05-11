class Solution:

    def adjecent(self, i: int, j: int, n: int, m: int) -> List[int]:
        ret = []
        if i > 0:
            ret.append((i-1, j))
        if i < n-1:
            ret.append((i+1, j))
        if j > 0:
            ret.append((i, j-1))
        if j < m-1:
            ret.append((i, j+1))
        
        return ret

    def numIslands(self, grid: List[List[str]]) -> int:
        # flood fill algorithm

        visited = [[False for x in row] for row in grid]
        n = len(grid)
        m = len(grid[0])

        ret = 0
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x == "1" and not visited[i][j]:
                    # new island
                    ret += 1
                    visit = [(i,j)]
                    while visit:
                        # explore new island
                        pos = visit.pop()
                        x, y = pos[0], pos[1]
                        visited[x][y] = True

                        adj = self.adjecent(x, y, n, m)
                        visit.extend(filter(lambda a: grid[a[0]][a[1]] == "1" and not visited[a[0]][a[1]], adj))

        return ret

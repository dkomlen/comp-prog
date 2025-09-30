from collections import deque

class Solution:

    def get_neighbours(self, x, y, maze):
        if x > 0:
            yield (x-1, y)
        if y > 0:
            yield (x, y-1)
        if x < len(maze) - 1:
            yield (x+1, y)
        if y < len(maze[0]) - 1:
            yield (x, y+1)

    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        [start_x, start_y] = entrance
        visited = [[False for _ in ys] for ys in maze]
        visited[start_x][start_y] = True

        q = deque([])
        q.append((start_x, start_y, 0))
        while q:
            x, y, k = q.popleft()
            if not (x == start_x and y == start_y) and (x == 0 or y == 0 or x == len(maze) - 1 or y == len(maze[0]) - 1):
                return k

            for nx, ny in self.get_neighbours(x, y, maze):
                if maze[nx][ny] == '.' and not visited[nx][ny]:
                    q.append((nx, ny, k + 1))
                    visited[nx][ny] = True

        return -1
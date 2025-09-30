from collections import deque
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        visited = [False for _ in isConnected]
        sol = 0
        for i, _ in enumerate(isConnected):
            if visited[i]:
                continue
            sol += 1

            # bfs traversal of the province
            q = deque([])
            q.append(i)
            while q:
                k = q.popleft()
                visited[k] = True
                neighbours = [j for j, _ in enumerate(isConnected[k]) if isConnected[k][j] and not visited[j]]
                q.extend(neighbours)
                
        return sol
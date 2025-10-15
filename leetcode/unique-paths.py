class Solution:

    def get(self, dp, i, j, m, n):
        if i < 0 or j < 0 or i >= m or j >= n:
            return 0
        else:
            return dp[i][j]

    def uniquePaths(self, m: int, n: int) -> int:
        dp = [list([0] * n) for _ in range(m)]
        dp[0][0] = 1
        for i in range(m):
            for j in range(n):
                dp[i][j] += self.get(dp, i-1, j, m, n) + self.get(dp, i, j-1, m, n)
        
        return dp[m-1][n-1]
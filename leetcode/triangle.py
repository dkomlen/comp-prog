class Solution:
    def get_above(self, i: int, j: int, triangle: list[list[int]]) -> tuple[int, int]:
        row = i-1
        col_1 = j
        col_2 = j - 1
        if col_1 >= len(triangle[row]):
            col_1 = len(triangle[row]) - 1
        if col_2 < 0:
            col_2 = 0
        return (triangle[row][col_1], triangle[row][col_2])
    
    def minimumTotal(self, triangle: list[list[int]]) -> int:
        dp = [[0] * len(x) for x in triangle]
        dp[0][0] = triangle[0][0]
        for i in range(1, len(triangle)):
            for j in range(len(triangle[i])):
                (x, y) = self.get_above(i, j, dp)
                dp[i][j] = min(x + triangle[i][j], y + triangle[i][j])

        return min(dp[-1])
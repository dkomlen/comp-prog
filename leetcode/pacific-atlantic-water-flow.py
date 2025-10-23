
class Solution:

    def get_cells(self, i, j, visited_val, heights, touch_map):
        m = len(heights)
        n = len(heights[0])
        cells = [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]
        return list(filter(lambda c:
                           c[0] >= 0 and c[0] < m and c[1] >= 0 and c[1] < n
                           and touch_map[c[0]][c[1]] != visited_val
                           and heights[c[0]][c[1]] >= heights[i][j], cells))

    def fill_map(self, i, j, visited_val, sol_val, heights, touch_map):
        ret = []
        cells = [(i, j)]

        while cells:
            (i, j) = cells.pop()

            if touch_map[i][j] % visited_val:
                touch_map[i][j] *= visited_val
                cells.extend(self.get_cells(i, j, visited_val, heights, touch_map))

                if touch_map[i][j] % sol_val == 0:
                    ret.append([i, j])

        return ret

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        touch_map = [[1] * len(heights[0]) for _ in range(len(heights))]
        m = len(heights)
        n = len(heights[0])

        # pacific
        for i in range(m):
            self.fill_map(i, 0, 2, 6, heights, touch_map)

        for j in range(n):
            self.fill_map(0, j, 2, 6, heights, touch_map)
        
        ret = []
        # atlantic
        for i in range(m):
            ret.extend(self.fill_map(i, n-1, 3, 6, heights, touch_map))

        for j in range(n):
            ret.extend(self.fill_map(m-1, j, 3, 6, heights, touch_map))

        return ret
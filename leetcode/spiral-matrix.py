class Solution:
    def next_pos(self, pos, direction, m, n):
        x, y = pos
        next = None
        if direction == 'right' and y < n-1:
            return (x, y+1)
        if direction == 'left' and y > 0:
            return (x, y-1)
        if direction == 'down' and x < m-1:
            return (x+1, y)
        if direction == 'up' and x > 0:
            return (x-1, y)
        return None

    def next_direction(self, dir):
        if dir == 'right':
            return 'down'
        if dir == 'left':
            return 'up'
        if dir == 'down':
            return 'left'
        if dir == 'up':
            return 'right'  

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        visited = [[False for x in row] for row in matrix]
        m = len(matrix)
        n = len(matrix[0])
        cur_pos, next_pos = None, (0,0)
        direction = 'right'
        ret = []

        while(True):
            if next_pos is None or visited[next_pos[0]][next_pos[1]]:
                if turned:
                    break
                else:
                    turned = True
                    direction = self.next_direction(direction)
                    next_pos = self.next_pos(pos, direction, m, n)

            else:
                turned = False
                pos = next_pos
                visited[next_pos[0]][next_pos[1]] = True
                ret.append(matrix[pos[0]][pos[1]])
                next_pos = self.next_pos(pos, direction, m, n)

        return ret

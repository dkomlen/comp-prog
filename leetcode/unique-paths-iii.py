from typing import List, Set, Tuple

class Solution:

    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        (sm, sn) = (None, None)
        total = 1
        for m in range(len(grid)):
            for n in range(len(grid[0])):
                if grid[m][n] == 1:
                    (sm, sn) = (m,n)

                if grid[m][n] == 0:
                    total += 1

        return self.__traverse(grid, sm, sn, set(), total)

    def __traverse(self, grid: List[List[int]], m: int, n: int, visited: Set[Tuple[int, int]], total: int) -> int:
        """ Returns number of ways to go from (m,n) to ending square with total visited squares
        """
        # We are on ending square and we traversed total number of squares
        if grid[m][n] == 2 and len(visited) == total:
            return 1

        result = 0
        visited.add((m,n))
        for dm in [-1, 0, 1]:
            for dn in [-1, 0, 1]:
                if (dn == 0 or dm == 0) and self.__is_valid_move(grid, m+dm, n+dn, visited):
                    result += self.__traverse(grid, m+dm, n+dn, visited, total)

        visited.remove((m,n))
        return result

    def __is_valid_move(self, grid, m: int, n: int, visited: Set[Tuple[int, int]]):
        # Invalid moves outside of grid
        if m < 0 or n < 0 or m >= len(grid) or n >= len(grid[0]):
            return False

        # Invalid move to non empty square
        if grid[m][n] == -1:
            return False

        # Invalid move to visited square
        if (m,n) in visited:
            return False

        return True
class Solution:

    def setCol(self, col, matrix: List[List[int]]) -> None:
        for row in matrix:
            row[col] = 0

    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows = set({})
        cols = set({})
        for k, row in enumerate(matrix):
            for i, x in enumerate(row):
                if x == 0:
                    rows.add(k)
                    cols.add(i)
        
        for k, row in enumerate(matrix):
            for i, x in enumerate(row):
                if k in rows or i in cols:
                    matrix[k][i] = 0

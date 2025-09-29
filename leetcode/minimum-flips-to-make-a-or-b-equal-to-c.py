class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        sol = 0
        while a or b or c:
            x = a & 1
            y = b & 1
            target = c & 1
            if x & y and target == 0:
                sol += 2
            elif x | y and target == 0:
                sol += 1
            elif x == 0 and y == 0 and target == 1:
                sol += 1

            a >>= 1
            b >>= 1
            c >>= 1

        return sol
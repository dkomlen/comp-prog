class Solution:
    def minCosts(self, cost: List[int]) -> List[int]:
        sol = []
        for x in cost:
            if not sol:
                sol.append(x)
            else:
                sol.append(min(sol[-1], x))

        return sol

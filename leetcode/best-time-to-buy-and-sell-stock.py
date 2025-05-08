class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        buy = prices[0]
        sol = 0
        for x in prices:
            if x > buy:
                buy = x
            else:
                sol = max(sol, buy - x)
        return sol
        
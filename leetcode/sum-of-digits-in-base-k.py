class Solution:
    def sumBase(self, n: int, k: int) -> int:
        sol = 0
        while n:
            sol += n % k
            n //= k

        return sol

print(Solution().sumBase(34,6))
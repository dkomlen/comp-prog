class Solution:
    def countSubstrings(self, s: str) -> int:
        sol = 0
        for i, _ in enumerate(s):
            for j, _ in enumerate(s[:i+1]):
                candidate = s[j:i+1]
                if candidate == candidate[::-1]:
                    sol += 1
        return sol

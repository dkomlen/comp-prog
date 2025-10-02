class Solution:
    def romanToInt(self, s: str) -> int:

        sol = 0
        last = None

        for c in s[::-1]:
            if c == 'I':
                if last == 'V' or last == 'X':
                    sol -= 1
                else:
                    sol += 1
            elif c == 'X':
                if last == 'L' or last == 'C':
                    sol -= 10
                else:
                    sol += 10
            elif c == 'L':
                sol += 50
            elif c == 'C':
                if last == 'D' or last == 'M':
                    sol -= 100
                else:
                    sol += 100
            elif c == 'V':
                sol += 5
            elif c == 'D':
                sol += 500
            elif c == 'M':
                sol += 1000

            last = c

        return sol

print(Solution().romanToInt('MCMXCIV'))
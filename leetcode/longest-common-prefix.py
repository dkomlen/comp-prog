class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        pos = 0
        sol = []
        while True:

            cur = ''
            for i, s in enumerate(strs):
                if pos + 1 > len(s):
                    return ''.join(sol)

                if i == 0:
                    cur = s[pos]
                elif s[pos] != cur:
                    return ''.join(sol)
                    
            sol.append(cur)
            pos += 1
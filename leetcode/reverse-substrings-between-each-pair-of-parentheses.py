class Solution:
    def reverseParentheses(self, s: str) -> str:
        if not s:
            return s

        open_b, bracks = [], []
        for i, c in enumerate(s):
            if c == '(':
                open_b.append(i)
            elif c == ')':
                bracks.append((open_b.pop(), i))

        for (ob, cb) in bracks:
            s = s[:ob] + s[ob:cb+1][::-1] + s[cb+1:]

        s = s.replace(')', '').replace('(', '')
        return s

print(Solution().reverseParentheses("(ed(et(oc))el)"))
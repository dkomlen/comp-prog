class Solution:
    def removeStars(self, s: str) -> str:
        rem = 0
        ret = []
        for c in s[::-1]:
            if c == '*':
                rem += 1
            elif rem:
                rem -= 1
            else:
                ret.append(c)
        return ''.join(ret[::-1])
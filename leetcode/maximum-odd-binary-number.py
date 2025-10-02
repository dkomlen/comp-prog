class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        s = s.replace('1', '0', 1)
        ret = sorted(list(s))
        ret[0] = '1'
        return ''.join(ret[::-1])
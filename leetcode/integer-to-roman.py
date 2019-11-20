class Solution:

    def helper(self, pos, num):
        chrs = [('I', 'V', 'X'), ('X', 'L', 'C'), ('C', 'D', 'M'), ('M', '-', '-')]
        (i,v,x) = chrs[pos]
        if num < 4:
            return i * num
        elif num == 4:
            return i + v
        elif num == 5:
            return v
        elif num < 9:
            return v + (num - 5) * i
        elif num == 9:
            return i + x

    def intToRoman(self, num: int) -> str:
        pos = 0
        ret = ""
        while num:
            x = num % 10
            num //= 10

            ret = self.helper(pos, x) + ret
            pos +=1
        return ret

print(Solution().intToRoman(1994))
class Solution:

    def sum(self, num1, num2) -> str:
        c = 0
        ret = []
        while num1 or num2:
            if num1:
                x = int(num1[-1])
                num1 = num1[:-1]
            else:
                x = 0
            if num2:
                y = int(num2[-1])
                num2 = num2[:-1]
            else:
                y = 0
            ret.append(str((x+y+c)%10))
            c = (x+y+c)//10
        
        if c:
            ret.append(str(c))

        return ''.join(ret[::-1])

    def multiply(self, num1: str, num2: str) -> str:
        
        if num1 == "0" or num2 == "0":
            return "0"

        ret = ""
        c = 0
        while num2:
            y = num2[0]
            num2 = num2[1:]
            c = 0
            ys = []
            for x in num1[::-1]:
                z = int(x) * int(y) + c
                ys.append(str(z % 10))
                c = z // 10
            
            if c:
                ys.append(str(c))

            ret += "0"
            ret = self.sum(ret, ''.join(ys[::-1]))
    
        return ret

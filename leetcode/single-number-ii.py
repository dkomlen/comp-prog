class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        sol = 0

        # 0 1 0
        # 0 1 0  
        # 0 1 0
        # 1 1 0
        # -----
        # 1 1 0
        # & 0 1 0
        # | 1 1 0
        
        pos = [0] * 32
        neg = [0] * 32
        for x in nums:
            for i in range(32):
                if x > 0:
                    pos[i] += (x >> i) & 1
                    pos[i] %= 3
                else:
                    neg[i] += ((-1 * x) >> i) & 1
                    neg[i] %= 3
        
        for i in range(32):
                sol += pos[i] << i
                sol += -1 * (neg[i] << i)

        return int(sol)
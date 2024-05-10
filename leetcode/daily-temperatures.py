class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:

        # temp[t][i] -> min days to wait from day i for temp to be = t, 0 -> not possible
        
        # example:
        # 30 [0, 0, 0, 0]
        # 40 [1, 0, 0, 0]
        # 50 [2, 1, 0, 0]
        # 60 [3, 2, 1, 0]

        temp = [[0 for i in temperatures] for j in range(71)]

        for t in range(70,-1,-1):
            same_temp_d = 0
            for i in range(len(temperatures)-1,-1,-1):
                if temperatures[i] == 30 + t:
                    same_temp_d = 1
                elif same_temp_d > 0:
                    temp[t][i] = same_temp_d
                    same_temp_d += 1
        
        ret = []
        for i, t in enumerate(temperatures):
            m = 0
            for x in range(t-30, 71):
                if m == 0:
                    m = temp[x][i]
                elif temp[x][i] > 0:
                    m = min(m, temp[x][i])
            ret.append(m)

        return ret

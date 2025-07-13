from collections import deque

class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        q_dire = deque()
        q_radiant = deque()

        for i, x in enumerate(senate):
            if x == 'R':
                q_radiant.append(i)
            else:
                q_dire.append(i)

        while q_radiant and q_dire:
            r = q_radiant.popleft()
            d = q_dire.popleft()

            g = max(q_radiant[-1] if q_radiant else 0, q_dire[-1] if q_dire else 0) + 1
            if r < d:
                q_radiant.append(g)
            else:
                q_dire.append(g)

        return 'Dire' if q_dire else 'Radiant'
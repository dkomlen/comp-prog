from collections import Counter
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        window = len(p)
        target = Counter(p)
        candidate = Counter()

        win_start = 0
        res = []

        for i, x in enumerate(s):
            candidate.update(x)
            if i >= window:
                candidate.subtract(s[win_start])
                win_start += 1
            
            if target == candidate:
                res.append(win_start)
    
        return res
            
from typing import List
from collections import Counter

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        ret = sorted([(-f,w) for (w,f) in Counter(words).items()])[:k]
        return [w for f,w in ret]

print(Solution().topKFrequent(["i", "love", "leetcode", "i", "love", "coding"], k = 2))
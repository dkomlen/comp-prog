from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        return map(lambda x: x[1], sorted([(-f,v) for v, f in Counter(nums).items()])[:k])
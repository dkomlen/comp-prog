from collections import Counter

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        processed = set()
        ret = 0

        for x in nums:
            if x in processed:
                continue
            y = x
            cur_len = 0
            while y in nums:
                processed.add(y)
                cur_len += 1
                y += 1
            
            y = x - 1
            while y in nums:
                processed.add(y)
                cur_len += 1
                y -= 1

            ret = max(ret, cur_len)

        return ret
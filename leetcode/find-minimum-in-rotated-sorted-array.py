from typing import List

class Solution:
    def findMin(self, nums: List[int]) -> int:

        l, r, m = 0, len(nums) - 1, 0
        while l <= r:
            m = (l + r) // 2

            if m > 0 and nums[m-1] > nums[m]:
                return nums[m]
            elif nums[m] > nums[-1]:
                l = m + 1
            else:
                r = m - 1
        return nums[l]

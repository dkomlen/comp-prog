class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        max_right = nums[0]
        max_cur = nums[0]
        for x in nums[1:]:
            max_right = max(max_right + x, x)
            max_cur = max(max_cur, max_right)
        return max_cur
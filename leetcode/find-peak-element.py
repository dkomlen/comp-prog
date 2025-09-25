class Solution:

    def is_peak(self, nums: List[int], i):
        if len(nums) == 1:
            return True
        
        left_cond = True
        right_cond = True

        if i > 0:
            left_cond = nums[i] > nums[i-1]
        if i < len(nums) - 1:
            right_cond = nums[i] > nums[i+1]
        return left_cond and right_cond

    def left(self, nums: List[int], i):
        if i == 0:
            return nums[i]
        else:
            return nums[i-1]

    def right(self, nums: List[int], i):
        if i == len(nums) - 1:
            return nums[i]
        else:
            return nums[i+1]

    def findPeakElement(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        peak = (left+right) // 2

        while not self.is_peak(nums, peak):
            if self.left(nums, peak) > self.right(nums, peak):
                right = peak - 1
            else:
                left = peak + 1
            peak = (left + right) // 2
            
        return peak

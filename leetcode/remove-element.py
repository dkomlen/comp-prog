class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        slow = 0
        for slow, x in enumerate(nums):
            if val == x:
                break
            slow += 1
        
        for fast in range(slow + 1, len(nums)):
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
        
        return slow
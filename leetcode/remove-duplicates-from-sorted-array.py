class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        rem = []
        for i, x in enumerate(nums):
            if i > 0:
                if nums[i-1] == x:
                    rem.append(i)
        k = 0
        for i in rem:
            nums.pop(i-k)
            k += 1
        return len(nums)
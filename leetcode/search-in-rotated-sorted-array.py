class Solution:
    def contains(self, nums: list[int], target: int, left: int, right: int) -> bool:
        """
        binary search in nums - asc sorted list
        """
        if left > right:
            return -1
        if left == right:
            if nums[left] == target:
                return left
            else:
                return -1
        
        pivot = (left + right) // 2
        if target == nums[pivot]:
            return pivot
        elif target < nums[pivot]:
            return self.contains(nums, target, left, pivot)
        else:
            return self.contains(nums, target, pivot+1, right)

    def find_pivot(self, nums: list[int], left: int, right: int) -> int:
        """
        binary search for pivot - returns pivot index
        """
        
        if left == right:
            return left
        pivot = (left + right) // 2

        if nums[left] > nums[pivot]:
            return self.find_pivot(nums, left, pivot)
        elif nums[right] < nums[pivot+1]:
            return self.find_pivot(nums, pivot+1, right)
        else:
            return pivot+1 if nums[left] > nums[right] else left

    def search(self, nums: list[int], target: int) -> int:
        # phase 1: find pivot
        pivot = self.find_pivot(nums, 0, len(nums)-1)
        # phase 2: find target
        if target == nums[pivot]:
            return pivot
        elif target <= nums[len(nums)-1]:
            return self.contains(nums, target, pivot, len(nums)-1)
        else:
            return self.contains(nums, target, 0, pivot-1)


if __name__ == "__main__":
    sol = Solution()
    print(sol.search([3,1], 1))
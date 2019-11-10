
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        available = {}
        for i in range(len(nums)):
            xs = available.get(nums[i], [])
            xs.append(i)
            available[nums[i]] = xs
        for x in nums:
            if target-x in available:
                if x == target-x and len(available[x]) > 1:
                    return [available[x][0], available[target-x][1]]
                elif x != target-x:
                    return [available[x][0], available[target-x][0]]

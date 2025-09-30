class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        # nums = [1,7,3,6,5,6]
        # left_sum [0, 1, 8, -> 11, 17, 22]
        # right_sum [27, 20, 17, -> 11, 6, 0]

        left_sum = []
        right_sum = []
        sum = 0

        for x in nums:
            left_sum.append(sum)
            sum += x

        sum = 0
        for x in nums[::-1]:
            right_sum.append(sum)
            sum += x
        right_sum = right_sum[::-1]

        for i, (x,y) in enumerate(zip(left_sum, right_sum)):
            if x == y:
                return i
        
        return -1
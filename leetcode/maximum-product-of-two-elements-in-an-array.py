class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        m1, m2 = 0, 0
        for x in nums:
            if x > m1:
                if m1 > 0:
                    m2 = m1
                m1 = x
            else:
                m2 = max(m2, x)

        return (m1 - 1)*(m2 - 1)
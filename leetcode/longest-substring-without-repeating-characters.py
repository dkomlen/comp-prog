class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        ret = 0
        chars = set({})

        for i, x in enumerate(s):
            
            while i - left > 0 and x in chars:
                chars.remove(s[left])
                left += 1
            
            chars.add(x)
            ret = max(ret, i - left + 1)
    
        return ret

class Solution:
    def isPalindrome(self, x: int) -> bool:
        orig = x
        if x < 0:
            return False
        rev = 0
        while x:
            if x / 10:
                rev *= 10
                rev += x % 10
            x //= 10
        return rev == orig

if __name__ == '__main__':
    s = Solution()
    print(s.isPalindrome(121))
    print(s.isPalindrome(-121))
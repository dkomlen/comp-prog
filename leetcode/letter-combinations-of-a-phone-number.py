class Solution:

    def build(self, prefix: str, digits: str) -> List[str]:
        digit_to_chars = {
            "2": ["a", "b", "c"],
            "3": ["d", "e", "f"],
            "4": ["g", "h", "i"],
            "5": ["j", "k", "l"],
            "6": ["m", "n", "o"],
            "7": ["p", "q", "r", "s"],
            "8": ["t", "u", "v"],
            "9": ["w", "x", "y", "z"]
        }
        if digits == "":
            return [prefix]

        digit = digits[0]
        digits = digits[1:]

        res = []

        for c in digit_to_chars[digit]:
            res += self.build(prefix + c, digits)

        return res

    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":
            return []
        return self.build("", digits)
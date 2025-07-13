from collections import Counter

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        orig = Counter(word1)
        dest = Counter(word2)

        if len(orig) != len(dest):
            return False

        if orig.keys() != dest.keys():
            return False
        
        return sorted(orig.values()) == sorted(dest.values())

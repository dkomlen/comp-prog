import unittest
from collections import Counter

def checkMagazine(magazine, note):
    words = Counter(magazine.split())
    for word in note.split():
        if word in words and words[word] > 0:
            words[word] -= 1
        else:
            return False
    return True

class TestCheckMagazine(unittest.TestCase):

    def test_input0(self):
        magazine = "give me one grand today night"
        note = "give one grand today"
        self.assertEqual(checkMagazine(magazine, note), True)

    def test_input1(self):
        magazine = "two times three is not four"
        note = "two times two is four"
        self.assertEqual(checkMagazine(magazine, note), False)

    def test_input2(self):
        magazine = "ive got a lovely bunch of coconuts"
        note = "ive got some coconuts"
        self.assertEqual(checkMagazine(magazine, note), False)
        
if __name__ == "__main__":
    unittest.main()


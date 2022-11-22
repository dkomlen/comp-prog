#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'repeatedString' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. STRING s
#  2. LONG_INTEGER n
#

def repeatedString(s, n):
    c = s.count('a')
    l = len(s)
    return c * (n // l) + s[:n % l].count('a')

if __name__ == '__main__':
    s = input()
    n = int(input().strip())

    result = repeatedString(s, n)
    print(result)
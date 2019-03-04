#!/bin/python3

import math
import os
import random
import re
import sys

def maxSubsetSum(arr):
    """Preconditions: len(arr) > 1, min(arr) >= -10^4"""

    (se, sne) = (-(10**5), -(10**5))
    
    for x in arr:
        se_ = max(x, sne + x)
        sne_ = max(sne, se)
        se = se_
        sne = sne_

    return max(se, sne)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    n = int(input())
    arr = list(map(int, input().rstrip().split()))
    res = maxSubsetSum(arr)
    fptr.write(str(res) + '\n')
    fptr.close()

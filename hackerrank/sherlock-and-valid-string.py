#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter

def isValid(s):
    mp = Counter(Counter(s).values())
    if len(mp) > 2:
        return "NO"
    elif len(mp) == 2:
        res = dict((v,k) for k,v in mp.items())
        (keys, vals) = (list(mp.keys()), list(mp.values()))
        print(mp, res, vals, min(mp), max(mp))
        if mp[max(mp)] > 1:
            if mp[min(mp)] == 1:
                return "YES"
            else:
                return "NO"
        if abs(keys[0] - keys[1]) > 1:
            return "NO"
    return "YES"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()
    result = isValid(s)
    fptr.write(result + '\n')

    fptr.close()

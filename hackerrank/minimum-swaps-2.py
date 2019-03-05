#!/bin/python3

import math
import os
import random
import re
import sys

def minimumSwaps(arr):
    idx = list(arr)
    for i, x in enumerate(arr):
        idx[x-1] = i
    swp = 0
    for i, x in enumerate(arr):
        j = idx[x-1]
        if j != i:
            t = arr[i]
            arr[i] = arr[j]
            arr[j] = t
            swp += 1
    return swp

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())
    arr = list(map(int, input().rstrip().split()))
    res = minimumSwaps(arr)
    fptr.write(str(res) + '\n')

    fptr.close()

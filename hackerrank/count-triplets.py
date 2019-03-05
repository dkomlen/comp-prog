#!/bin/python3

import math
import os
import random
import re
import sys

class Item():
    fs = 0
    sec = 0

def countTriplets(arr, r):
    lookup = {}
    sol = 0
    for i in arr:
        cur = lookup.get(i, Item())
        if i % r == 0:
            it = lookup.get(i/r, Item())
            sol += it.sec
            cur.sec += it.fs
        cur.fs += 1
        lookup[i] = cur

    return sol

if __name__ == '__main__':

    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nr = input().rstrip().split()
    n = int(nr[0])
    r = int(nr[1])
    arr = list(map(int, input().rstrip().split()))
    ans = countTriplets(arr, r)
    fptr.write(str(ans) + '\n')

    fptr.close()

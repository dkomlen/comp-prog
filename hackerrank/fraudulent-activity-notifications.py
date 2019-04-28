#!/bin/python3

import math
import os
import random
import re
import sys
from collections import deque


def median(buckets, d):
    s = 0
    last = 0

    for (val, ctr) in enumerate(buckets):
        if ctr > 0:
            s += ctr    
            if s > d//2 and d % 2 == 1:
                return val
            elif s > d//2 and d % 2 == 0:
                if ctr >= 2:
                    return val / 2
                else:
                    return (last + val) / 2

            last = val

def activityNotifications(ex, d):
    ret = 0
    buckets = [0] * 300
    queue = deque()

    for (i,x) in enumerate(ex):
        if i >= d:
            med = median(buckets,d)
            if (x >= med * 2):
                print(buckets)
                print(med)
                print(i, x)
                return 0
            ret += (x >= median(buckets,d) * 2)
            y = queue.popleft()
            buckets[y] -= 1

        buckets[x] += 1
        queue.append(x)

    return ret

if __name__ == '__main__':
    #fptr = open(os.environ['OUTPUT_PATH'], 'w')
    nd = input().split()
    n = int(nd[0])
    d = int(nd[1])
    expenditure = list(map(int, input().rstrip().split()))
    result = activityNotifications(expenditure, d)
    #fptr.write(str(result) + '\n')

    #fptr.close()
    print(result)
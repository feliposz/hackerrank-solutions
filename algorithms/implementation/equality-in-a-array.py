#!/bin/python

import math
import os
import random
import re
import sys

# Complete the equalizeArray function below.
def equalizeArray(arr):
    hist = [0] * 100;
    for x in arr:
        hist[x-1] += 1
    return len(arr) - max(hist);
    
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(raw_input())

    arr = map(int, raw_input().rstrip().split())

    result = equalizeArray(arr)

    fptr.write(str(result) + '\n')

    fptr.close()


#!/bin/python3

import math
import os
import random
import re
import sys




first_multiple_input = input().rstrip().split()

n = int(first_multiple_input[0])

m = int(first_multiple_input[1])

matrix = []

for _ in range(n):
    matrix_item = input()
    matrix.append(matrix_item)

output = [""] * len(matrix[0])

for s in matrix:
    for i in range(len(s)):
        output[i] += s[i]

result = "".join(output)
result = re.sub(r"([A-Za-z0-9])[^A-Za-z0-9]+([A-Za-z0-9])", r"\1 \2", result)
print(result)


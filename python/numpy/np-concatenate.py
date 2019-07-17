import numpy

import numpy

n, m, p = map(int, raw_input().split())

arr_n = []
for i in range(n):
    row = map(int, raw_input().split())
    arr_n.append(row)

arr_m = []
for i in range(m):
    row = map(int, raw_input().split())
    arr_m.append(row)

arr = numpy.concatenate((numpy.array(arr_n), numpy.array(arr_m)), axis=0)

print arr





import numpy

import numpy

n, m = map(int, raw_input().split())
data = []
for i in range(n):
    row = map(int, raw_input().split())
    data.append(row)
data = numpy.array(data)

min_1 = numpy.min(data, axis=1)
max_all = numpy.max(min_1)
print max_all




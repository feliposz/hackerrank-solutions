import numpy

n, m = map(int, raw_input().split())
data = []
for i in range(n):
    row = map(int, raw_input().split())
    data.append(row)
data = numpy.array(data)

data_sum_0 = numpy.sum(data, axis=0)
data_prod = numpy.prod(data_sum_0)

print data_prod





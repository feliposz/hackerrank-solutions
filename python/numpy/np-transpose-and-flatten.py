import numpy

n, m = map(int, raw_input().split())

arr = []
for i in range(n):
    row = map(int, raw_input().split())
    arr.append(row)

arr = numpy.array(arr)

print arr.transpose()
print arr.flatten()



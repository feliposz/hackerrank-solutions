import numpy

numpy.set_printoptions(legacy='1.13')

n, m = map(int, raw_input().split())

arr = []
for i in range(n):
    row = map(int, raw_input().split())
    arr.append(row)

a = numpy.array(arr)

print numpy.mean(a, axis=1)
print numpy.var(a, axis=0)
print numpy.std(a, axis=None)


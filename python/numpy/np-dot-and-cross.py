import numpy

numpy.set_printoptions(legacy='1.13')

n = input()

arr = []
for i in range(n):
    row = map(int, raw_input().split())
    arr.append(row)

a = numpy.array(arr)

arr = []
for i in range(n):
    row = map(int, raw_input().split())
    arr.append(row)

b = numpy.array(arr)

print numpy.matmul(a, b)



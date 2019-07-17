import numpy

numpy.set_printoptions(legacy='1.13')

n, m = map(int, raw_input().split())
print numpy.eye(n, m)




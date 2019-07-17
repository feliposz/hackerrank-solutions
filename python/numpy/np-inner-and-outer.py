
import numpy

numpy.set_printoptions(legacy='1.13')

a = numpy.array(map(int, raw_input().split()))
b = numpy.array(map(int, raw_input().split()))
    
print numpy.inner(a, b)
print numpy.outer(a, b)



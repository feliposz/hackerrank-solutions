import numpy

data = numpy.fromstring(raw_input(), dtype=float, sep=' ')

numpy.set_printoptions(sign=' ')

print numpy.floor(data)
print numpy.ceil(data)
print numpy.rint(data)



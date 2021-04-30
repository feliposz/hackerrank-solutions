import numpy

coef = list(map(float, input().split()))
x = float(input())

print(numpy.polyval(coef, x))


import numpy

n, m = map(int, raw_input().split())

arr_a = []
for i in range(n):
    row = map(int, raw_input().split())
    arr_a.append(row)

arr_b = []
for i in range(n):
    row = map(int, raw_input().split())
    arr_b.append(row)

a = numpy.array(arr_a)
b = numpy.array(arr_b)

print a+b
print a-b
print a*b
print a/b
print a%b
print a**b


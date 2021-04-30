import numpy

n = int(raw_input())

m = []
for _ in range(n):
    m.append(list(map(float, raw_input().split())))
    
print(round(numpy.linalg.det(m), 2))


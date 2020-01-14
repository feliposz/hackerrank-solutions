# Enter your code here. Read input from STDIN. Print output to STDOUT

from collections import deque

c = int(input())
d = deque()

for i in range(c):
    parts = input().split()
    method = parts[0]
    if len(parts) > 1:
        value = int(parts[1])
        getattr(d, method)(value)
    else:
        getattr(d, method)()


for v in d:
    print(str(v) + ' ', end='')


# Enter your code here. Read input from STDIN. Print output to STDOUT

from itertools import product

k, m = map(int, input().split())
l = []

for _ in range(k):
    l.append(map(lambda x: int(x) ** 2, input().split()[1:]))

print(max(map(lambda i: sum(i) % m, product(*l))))



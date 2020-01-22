# Enter your code here. Read input from STDIN. Print output to STDOUT

from itertools import combinations

s, n = input().split()
s = sorted(s)
n = int(n)

for k in range(1, n+1):
    for c in combinations(s, k):
        print(''.join(c))


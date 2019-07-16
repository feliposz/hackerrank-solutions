# Enter your code here. Read input from STDIN. Print output to STDOUT

from collections import Counter

k = input()
t = map(int, raw_input().split())

c = Counter(t)
s = set(t)
for n in s:
    if c[n] == 1:
        print n
        break


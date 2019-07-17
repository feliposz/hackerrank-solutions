# Enter your code here. Read input from STDIN. Print output to STDOUT

import itertools

n = input()
xs = raw_input().split()
k = input()

ts = list(itertools.combinations(list(range(n)), k))

ct = 0
for t in ts:
    for i in t:
        if xs[i] == 'a':
            ct += 1
            break

print float(ct)/len(ts)



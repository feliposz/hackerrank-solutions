# Enter your code here. Read input from STDIN. Print output to STDOUT

from collections import OrderedDict

ordDict = OrderedDict()

n = int(input())
c = 0

while c < n:
    c = c + 1
    w = input().strip()
    if w in ordDict:
        ordDict[w] += 1
    else:
        ordDict[w] = 1

print(len(ordDict))
for v in ordDict.values():
    print(str(v) + ' ', end='')


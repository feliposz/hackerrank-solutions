# Enter your code here. Read input from STDIN. Print output to STDOUT

from collections import OrderedDict
import re

ordDict = OrderedDict()

n = int(input())
c = 0

while c < n:
    c = c + 1
    s = input().strip()
    m = re.search('(\D+) +(\d+)', s)
    #print(m)
    name = m.group(1)
    price = int(m.group(2))
    ordDict[name] = ordDict.get(name, 0) + int(price)

for name, price in ordDict.items():
    print(name, price)


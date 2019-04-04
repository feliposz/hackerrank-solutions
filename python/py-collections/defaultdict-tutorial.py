# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import defaultdict

d = defaultdict(lambda: '')

items, queries = map(int, raw_input().split(' '))

for i in range(items):
    word = raw_input()
    d[word] += "{0} ".format(i+1)

for _ in range(queries):
    word = raw_input()
    if d[word] != '':
        print d[word]
    else:
        print -1



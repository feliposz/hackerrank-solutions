# Enter your code here. Read input from STDIN. Print output to STDOUT

import re

t = input()

for _ in range(t):
    s = raw_input()
    try:
        p = re.compile(s)
        print 'True'
    except re.error as e:
        print 'False'


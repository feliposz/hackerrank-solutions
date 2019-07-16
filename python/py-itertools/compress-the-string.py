# Enter your code here. Read input from STDIN. Print output to STDOUT

import itertools

s = raw_input()

for k, g in itertools.groupby(s):
    print "(" + str(len(list(g))) + ", " + k + ")",


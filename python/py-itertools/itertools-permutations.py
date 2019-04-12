from itertools import permutations
string, size = raw_input().split(' ')
size = int(size)
ps = sorted(list(permutations(string, size)))
for p in ps:
    print ''.join(p)



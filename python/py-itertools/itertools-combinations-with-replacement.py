# Enter your code here. Read input from STDIN. Print output to STDOUT


from itertools import combinations_with_replacement

s, n = input().split()
s = sorted(s)
n = int(n)

for c in combinations_with_replacement(s, n):
    print(''.join(c))


# Enter your code here. Read input from STDIN. Print output to STDOUT

n, m = map(int, raw_input().split())
arr = map(int, raw_input().split())
a = set(map(int, raw_input().split()))
b = set(map(int, raw_input().split()))

h = 0
for x in arr:
    if x in a:
        h += 1
    elif x in b:
        h -= 1

print h


# Enter your code here. Read input from STDIN. Print output to STDOUT

a = set(map(int, raw_input().split()))
n = input()
r = True
for _ in range(n):
    b = set(map(int, raw_input().split()))
    if a&b == b and len(b) < len(a):
        None
    else:
        r = False
        break

print r


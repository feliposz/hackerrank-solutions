# Enter your code here. Read input from STDIN. Print output to STDOUT

# Enter your code here. Read input from STDIN. Print output to STDOUT

a_sz = input()
a = set(map(int, raw_input().split()))
n = input()
for _ in range(n):
    cmd, val = raw_input().split()
    val = int(val)
    b = set(map(int, raw_input().split()))
    if cmd == 'update':
        a |= b
    elif cmd == 'intersection_update':
        a &= b
    elif cmd == 'difference_update':
        a -= b
    elif cmd == 'symmetric_difference_update':
        a ^= b
print sum(a)




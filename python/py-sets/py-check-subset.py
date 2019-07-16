# Enter your code here. Read input from STDIN. Print output to STDOUT

t = input()

for _ in range(t):
    a_sz = input()
    a = set(map(int, raw_input().split()))
    b_sz = input()
    b = set(map(int, raw_input().split()))
    if a&b == a:
        print 'True'
    else:
        print 'False'


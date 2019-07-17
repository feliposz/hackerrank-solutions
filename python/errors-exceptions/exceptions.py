# Enter your code here. Read input from STDIN. Print output to STDOUT

n = input()

for _ in range(n):
    a, b = raw_input().split()
    try:
        print int(a)/int(b)
    except ValueError as e:
        print 'Error Code:', e
    except ZeroDivisionError as e:
        print 'Error Code:', e


# Enter your code here. Read input from STDIN. Print output to STDOUT
n, m = raw_input().split(' ')
n, m = int(n), int(m)
for i in range(n):
    if i == n / 2:
        s = 'WELCOME'
    elif i < n / 2:
        s = '.' + ('|..' * (i * 2)) + '|.'
    elif i > n / 2:
        s = '.' + ('|..' * ((n - i - 1) * 2)) + '|.'
    print s.center(m, '-')


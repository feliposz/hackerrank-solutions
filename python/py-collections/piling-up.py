# Enter your code here. Read input from STDIN. Print output to STDOUT

from collections import deque
T = int(input())
for _ in range(T):
    n = int(input())
    ss = list(map(int, input().split()))
    top = max(ss)
    d = deque(ss)
    res = "Yes"
    for _ in range(n):
        if d[0] >= d[-1]:
            if d[0] <= top:
                top = d.popleft()
            else:
                res = "No"
                break
        else:
            if d[-1] <= top:
                top = d.pop()
            else:
                res = "No"
                break
    print(res)


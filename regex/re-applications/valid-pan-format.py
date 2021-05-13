import re
pan = re.compile(r"[A-Z]{5}[0-9]{4}[A-Z]")
n = int(input())
for _ in range(n):
    if pan.match(input()):
        print("YES")
    else:
        print("NO")


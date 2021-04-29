import re
n = int(input())
for _ in range(n):
    mob = input()
    if re.match(r"^[7-9]\d{9}$", mob):
        print("YES")
    else:
        print("NO")
    


import re

hr = re.compile(r"hackerrank", re.IGNORECASE)

n = int(input())

count = 0
for _ in range(n):
    t = input()
    if hr.search(t):
        count += 1
print(count)


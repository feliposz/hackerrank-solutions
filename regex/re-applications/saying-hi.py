import re

criteria = re.compile(r"^[Hh][Ii]\s[^Dd].*")

n = int(input())

for _ in range(n):
    s = input()
    if criteria.match(s):
        print(s)


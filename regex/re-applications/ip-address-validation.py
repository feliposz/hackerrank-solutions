import re

v4 = re.compile(r"^[012]?\d{1,2}.[012]?\d{1,2}\.[012]?\d{1,2}\.[012]?\d{1,2}$")
v6 = re.compile(r"^[0-9a-f]{1,4}:[0-9a-f]{1,4}:[0-9a-f]{1,4}:[0-9a-f]{1,4}:[0-9a-f]{1,4}:[0-9a-f]{1,4}:[0-9a-f]{1,4}:[0-9a-f]{1,4}$", re.IGNORECASE)

n = int(input())

for _ in range(n):
    line = input()
    if v4.match(line):
        print("IPv4")
    elif v6.match(line):
        print("IPv6")
    else:
        print("Neither")



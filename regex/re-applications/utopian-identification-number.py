import re
utopian = re.compile(r"[a-z]{0,3}[0-9]{2,8}[A-Z]{3,}")
n = int(input())
for _ in range(n):
    s = input()
    if utopian.match(s):
        print("VALID")
    else:
        print("INVALID")


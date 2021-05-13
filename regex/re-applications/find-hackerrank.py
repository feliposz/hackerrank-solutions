import re

start_re = re.compile(r"^hackerrank")
end_re = re.compile(r"hackerrank$")

n = int(input())
for _ in range(n):
    line = input()
    if start_re.search(line) and end_re.search(line):
        print(0)
    elif start_re.search(line):
        print(1)
    elif end_re.search(line):
        print(2)
    else:
        print(-1)


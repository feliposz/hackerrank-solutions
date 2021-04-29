import re

test = input()

m = re.search(r"([A-Za-z0-9])\1", test)

if m:
    print(m.group(1))
else:
    print(-1)
    


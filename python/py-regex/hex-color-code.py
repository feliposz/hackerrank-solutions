import re
n = int(input())
color_re = re.compile(r"(?<!^)(#(?:[\da-f]{3}){1,2})", re.IGNORECASE)
for _ in range(n):
    color = input()
    for c in color_re.findall(color):
        print(c)
    


import re

coor = re.compile(r"^\([+-]?(\d{1,2}(?:\.\d+)?)\s*,\s*[+-]?(\d{1,3}(?:\.\d+)?)\s*\)$")

n = int(input())

for _ in range(n):
    c = input()
    m = coor.match(c) 
    if m:        
        x = float(m.group(1))
        y = float(m.group(2))
        #print(c, x, y)
        if x <= 90 and y <= 180:
            print("Valid")
        else:
            print("Invalid")
    else:
        print("Invalid")


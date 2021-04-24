import re

n = int(input())

for _ in range(n):
    name = input()
    regexp = r"^[_\.][0-9]+[A-Za-z]*_?$"
    if re.match(regexp, name):
        print("VALID")
    else:
        print("INVALID")
        


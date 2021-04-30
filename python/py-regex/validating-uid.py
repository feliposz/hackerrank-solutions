import re

valid_re = re.compile(r"[a-zA-Z0-9]{10}")
upper_re = re.compile(r"[A-Z]")
digit_re = re.compile(r"[0-9]")

n = int(input())

for _ in range(n):
    test = input()
    result = False
    if valid_re.match(test):
        if len(upper_re.findall(test)) >= 2 and len(digit_re.findall(test)) >= 3:
            if len(test) == len(set(test)):
                result = True
    if result:
        print("Valid")
    else:
        print("Invalid")


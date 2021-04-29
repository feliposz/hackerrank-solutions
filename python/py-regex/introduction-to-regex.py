import re

n = int(input())

float_re = re.compile(r"^[+-\.]?(\d+\.\d*|\d*\.\d+)")

for _ in range(n):
    test = input()
    ok = False
    if re.match(float_re, test):
        try:
            float(test)
            ok = True
        except:
            ok = False
    print(ok)


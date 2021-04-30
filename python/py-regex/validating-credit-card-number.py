import re

valid_re = re.compile(r"^[456]\d{3}-?\d{4}-?\d{4}-?\d{4}$")
consecutive_re = re.compile(r"(\d)\1{3}")

n = int(input())

for _ in range(n):
    test = input()
    result = False
    if valid_re.match(test):
        if not consecutive_re.search(test.replace("-", "")):
            result = True
    if result:
        print("Valid")
    else:
        print("Invalid")


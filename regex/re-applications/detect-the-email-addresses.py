import re
from collections import defaultdict

n = int(input())

text = ""
for _ in range(n):
    text += input() + "\n"
    
emails = re.findall(r"[A-Za-z0-9_]+(?:\.[A-Za-z0-9_]+)*@[A-Za-z0-9_]+(?:\.[A-Za-z0-9_]+)*", text)

print(";".join(sorted(set(emails))))


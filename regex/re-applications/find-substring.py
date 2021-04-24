import re

n = int(input())

ss = []

for _ in range(n):
    ss.append(input())
    
q = int(input())

for _ in range(q):
    count = 0
    word = input()
    regexp = r"[A-Za-z0-9_]+" + word + r"[A-Za-z0-9_]+"
    for s in ss:
        count += len(re.findall(regexp, s))
    print(count)        


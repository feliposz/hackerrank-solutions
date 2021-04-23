import re

sentences = []
words = []

n = int(input())
for _ in range(n):
    sentences += re.findall(r"[A-Za-z0-9_]+", input())
    
t = int(input())
for _ in range(t):
    w = input()
    c = sentences.count(w)
    print(c)


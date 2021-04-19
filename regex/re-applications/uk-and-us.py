import re

n = int(input())
sentences = []
for _ in range(n):
    sentences.append(input().split(' '))

t = int(input())
for _ in range(t):
    count = 0
    word = input()
    if word.endswith('se'):
        word2 = re.sub(r"se$", "ze", word)
    elif word.endswith('ze'):
        word2 = re.sub(r"ze$", "se", word)
    for sentence in sentences:
        for w in sentence:
            if w == word or w == word2:
                count += 1
    print(count)



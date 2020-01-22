s = input()

h = {}

for c in s:
    h[c] = h.get(c, 0) + 1

o = sorted(sorted(h.items(), key=lambda i: i[0]), key=lambda i: i[1], reverse=True)

for n in range(3):
    print(o[n][0], o[n][1])


# Enter your code here. Read input from STDIN. Print output to STDOUT
n, x = map(int, input().split())
g = []
for _ in range(x):
    g.append(list(map(float, input().split())))
for h in zip(*g):
    print(sum(h)/len(h))


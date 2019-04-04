# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import Counter
_ = raw_input()
shoes_list = map(int, raw_input().split(' '))
shoes = Counter(shoes_list)
total = 0
for _ in range(input()):
    data = raw_input().split(' ')
    size = int(data[0])
    value = int(data[1])
    if shoes[size] > 0:
        total += value
        shoes[size] -= 1
print total


import re
s = input()
k = input()
pattern = re.compile(k)

result = pattern.search(s)
if not result: 
    print("(-1, -1)")
while result:
    print("({0}, {1})".format(result.start(), result.end() - 1))
    result = pattern.search(s, result.start()+1)


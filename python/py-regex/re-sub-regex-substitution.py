import re
n = int(input())
def logic(match):
    if match.group(1) == "&&":
        return "and"
    else:
        return "or"
for _ in range(n):
    line = input()
    print(re.sub(r"(?<= )(&&|\|\|)(?= )", logic, line))
    


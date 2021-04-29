import re

test = input()

result = re.findall(r"(?<=[bcdfghjklmnpqrstvwxyz])[aeiou]{2,}(?=[bcdfghjklmnpqrstvwxyz])", test, re.IGNORECASE)

if len(result) > 0:
    print("\n".join(result))
else:
    print(-1)


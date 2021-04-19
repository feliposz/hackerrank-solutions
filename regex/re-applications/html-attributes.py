import re

n = int(input())

tags = {}

for _ in range(n):
    for tag in re.findall(r"<[^/].*?>", input()):
        m = re.search(r"<(\S+) ?(.*)>", tag)
        if m.group(1) not in tags:
            tags[m.group(1)] = set()
        if m.groups != 2:
            attrs = re.findall(r"([^ =]+)\s*=['\"]", m.group(2))
            tags[m.group(1)] |= set(attrs)

for tag in sorted(tags):
    print(tag + ":" + ",".join(sorted(tags[tag])))


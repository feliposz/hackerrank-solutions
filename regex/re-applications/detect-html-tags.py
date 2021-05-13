import sys
import re

#tag1_re = re.compile(r"<\s*(\S+)[^>]*?>.*?</\1>")
tag2_re = re.compile(r"<\s*([A-Za-z0-9]+)[^<]*?/>")
tag3_re = re.compile(r"</\s*([A-Za-z0-9]+)\s*>")
text = " ".join(sys.stdin.readlines())

tags = []
pos = 0

#while True:
#    m = tag1_re.search(text, pos)
#    if m:
#        tags.append(m.group(1))
#        pos = m.start() + 1
#    else:
#        break

for m in tag2_re.finditer(text):
    tags.append(m.group(1))

for m in tag3_re.finditer(text):
    tags.append(m.group(1))    
    
tags = list(sorted(set(tags)))
print(";".join(tags))

#print(tag2_re.findall(text))

# a;b;div;h2;li;span;ul
# a;b;div;  ;li;span;ul


import re
import sys

single = re.compile(r"//.*")
multi_single = re.compile(r"/\*.*\*/") 
multi_begin = re.compile(r"/\*.*")
multi_end = re.compile(r".*\*/")

lines = sys.stdin.readlines()
multi = False
for s in lines:
    if multi:
        x = multi_end.search(s)
        if x:
            print(x.group().lstrip())
            multi = False
        else:
            print(s.strip())
    else:
        a = single.search(s)
        b = multi_single.search(s)
        c = multi_begin.search(s)
        
        if a:
            print(a.group())
        elif b:
            print(b.group())
        elif c:
            print(c.group())
            multi = True


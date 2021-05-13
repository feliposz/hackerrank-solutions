import sys
import re

java = re.compile(r"import\s.+;")
python = re.compile(r"(def|print)\s")
c = re.compile(r"#include")

lines = sys.stdin.readlines()
for line in lines:
    if java.search(line):
        print("Java")
        break
    if python.search(line):
        print("Python")
        break
    if c.search(line):
        print("C")
        break
        


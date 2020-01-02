# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import namedtuple
n = int(input())
Student = namedtuple('Student', input())
c = 0
t = 0
while c < n:
    s = Student._make(input().split())
    t = t + int(s.MARKS)
    c = c + 1
print(t/n)


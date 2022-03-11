# Enter your code here. Read input from STDIN. Print output to STDOUT

n = input()
a = set(map(int, raw_input().split()))
m = input()
b = set(map(int, raw_input().split()))
print len(a-b)


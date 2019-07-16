# Enter your code here. Read input from STDIN. Print output to STDOUT

n = input()
xs = map(int, raw_input().split())
print (all(map(lambda x: x>0, xs)) and any(map(lambda x: str(x)==str(x)[::-1], xs)))


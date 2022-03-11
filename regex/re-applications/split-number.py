# Enter your code here. Read input from STDIN. Print output to STDOUT
import re

n = int(input())

for _ in range(n):
    phone = input()
    m = re.search(r"(\d+)[ -](\d+)[ -](\d+)", phone)
    print("CountryCode=" + m.group(1) + ",LocalAreaCode=" + m.group(2) + ",Number=" + m.group(3));
    


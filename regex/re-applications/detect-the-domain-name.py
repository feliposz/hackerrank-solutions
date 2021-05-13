import re

def cleanup_domain(s):    
    if s.startswith("http://"):
        s = s[7:]
    if s.startswith("https://"):
        s = s[8:]
    if s.startswith("www."):
        s = s[4:]
    if s.startswith("ww2."):
        s = s[4:]        
    return s

n = int(input())

domains = []

domain_re = re.compile(r"https?://[A-Za-z0-9\-]+(?:\.[A-Za-z0-9\-]+)+")

for _ in range(n):
    line = input()    
    domains += re.findall(domain_re, line)
    
domains = list(sorted(set(map(cleanup_domain, domains))))
#domains = [ d for d in domains if domain_re.match(d) ]

print(";".join(domains))


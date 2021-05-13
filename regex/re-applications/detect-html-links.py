import sys
import re
link_re = re.compile(r"<a[^>]*>.*?</a>")
href1_re = re.compile(r"href='([^']*)'")
href2_re = re.compile(r'href="([^"]*)"')
tags_re = re.compile(r"<[^>]+>")
text = " ".join(sys.stdin.readlines())
for link in link_re.findall(text):
    m1 = href1_re.search(link)
    m2 = href2_re.search(link)
    if m1:
        href = m1.group(1)
    elif m2:
        href = m2.group(1)
    else:
        href = ""
    title = re.sub(tags_re, "", link).strip()
    print(href + "," + title)
    
    


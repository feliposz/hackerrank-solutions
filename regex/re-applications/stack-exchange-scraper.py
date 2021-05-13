import sys
import re
text = " ".join(sys.stdin.readlines())

q_re = re.compile(r'href="/questions/(\d+)/')
s_re = re.compile(r'class="question-hyperlink">([^<]+)</a>')
t_re = re.compile(r'class="relativetime">([^<]+)</span>')
pos = 0
while True:
    m = q_re.search(text, pos)
    if m:
        qid = m.group(1)
        pos = m.end()
        m = s_re.search(text, pos)
        question = ""
        if m:
            question = m.group(1)
            pos = m.end()
        m = t_re.search(text, pos)
        time = ""
        if m:
            time = m.group(1)
            pos = m.end()
        print(qid + ";" + question + ";" + time)
    else:
        break


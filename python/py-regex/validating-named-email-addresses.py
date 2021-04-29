import re
n = int(input())
mail_re = re.compile(r"^.*<[A-Za-z][A-Za-z0-9-\._]*@[a-z]+\.[a-z]{1,3}>$")
for _ in range(n):
    mail = input()
    if mail_re.match(mail):
        print(mail)


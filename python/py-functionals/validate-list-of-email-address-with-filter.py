import re

mail_re = re.compile(r"^[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\.[a-zA-Z]{1,3}$")

def fun(s):
    if mail_re.match(s):
        return True
    else:
        return False



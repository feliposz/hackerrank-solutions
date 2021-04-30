def wrapper(f):
    def fmt(num):
        a = num[-10:-5]
        b = num[-5:]
        #print(a)
        #print(b)
        return "+91 %s %s" % (a, b)
    def fun(l):
        return f(map(fmt, l))
    return fun



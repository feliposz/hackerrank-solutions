# Enter your code here. Read input from STDIN. Print output to STDOUT

def my_cmp(a, b):
    if a.islower():
        if b.islower():
            return cmp(a, b)
        else:
            return -1
    elif a.isupper():
        if b.isupper():
            return cmp(a, b)
        elif b.islower():
            return 1
        else:
            return -1
    elif a.isdigit():
        if b.isdigit():
            if int(a)%2 == int(b)%2:
                return cmp(a, b)
            else:
                return int(b)%2 - int(a)%2
        else:
            return 1
    return cmp(a, b)

print ''.join(sorted(raw_input(), cmp=my_cmp))


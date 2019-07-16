n = input()
s = set(map(int, raw_input().split()))

m = input()
for _ in range(m):
    cmd = raw_input()
    if cmd == 'pop':
        s.pop()
    else:
        cmd, val = cmd.split()
        if cmd == 'remove':
            s.remove(int(val))
        elif cmd == 'discard':
            s.discard(int(val))
print sum(s)


N = int(raw_input())

l = []

for _ in range(N):
    line = raw_input().split(' ')
    cmd = line[0]
    if cmd == 'insert':
        pos = int(line[1])
        val = int(line[2])
        l.insert(pos, val)
    elif cmd == 'print':
        print l
    elif cmd == 'remove':
        val = int(line[1])
        l.remove(val)
    elif cmd == 'append':
        val = int(line[1])
        l.append(val)
    elif cmd == 'sort':
        l.sort()
    elif cmd == 'pop':
        l.pop()
    elif cmd == 'reverse':
        l.reverse()


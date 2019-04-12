def merge_the_tools(string, k):
    for pos in range(0, len(string), k):
        sub = string[pos:pos+k]
        c_set = set()
        out = ''
        for c in sub:
            if not c in c_set:
                out += c
                c_set.add(c)
        print out



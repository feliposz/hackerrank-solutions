

def wrap(string, max_width):
    out = ''
    for i in range(0, len(string), max_width):
        out += string[i:i+max_width] + '\n'
    return out



def print_rangoli(size):
    rows = size*2-1
    rowsize = size*4-3
    for i in range(rows):
        line = []
        for j in range(rowsize):
            c = '-'
            if j % 2 == 0:
                n = abs(rowsize/2-j)/2+abs(rows/2-i)
                if n < size:
                    c = chr(ord('a')+n)
            line.append(c)
        print ''.join(line)



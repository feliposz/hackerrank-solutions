def print_formatted(number):
    w = len(format(number, 'b'))
    for i in range(1, number+1):
        print "{0:{width}d} {0:{width}o} {0:{width}X} {0:{width}b}".format(i, width=w)



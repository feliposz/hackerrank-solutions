def minion_game(string):
    stuart = 0
    kevin = 0
    for start in range(len(string)):
        x = len(string)-start
        if string[start] in 'AEIOU':
            kevin += x
        else:
            stuart += x
        # for end in range(start+1, len(string)+1):
        #     sub = string[start:end]
        #     if len(sub) > 0:
        #         if sub[0] in 'AEIOU':
        #             kevin += 1
        #         else:
        #             stuart += 1
    if stuart > kevin:
        print 'Stuart ' + str(stuart)
    elif stuart < kevin:
        print 'Kevin ' + str(kevin)
    else:
        print 'Draw'




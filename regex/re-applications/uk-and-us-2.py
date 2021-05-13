n = int(input())

words = []

for _ in range(n):
    for w in input().split(" "):
        words.append(w)
        
t = int(input())

for _ in range(t):
    w1 = input()
    w2 = w1.replace("our", "or")
    count = 0
    #print(w1, w2)
    for w in words:
        #print(w)
        if w == w1 or w == w2:
            count += 1    
    print(count)
    
'''    

'''



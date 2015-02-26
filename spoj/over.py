def seq():
    p0 , p1 = 1, 3
    a = []
    a.append(1)
    a.append(3)
    k = 0
    while k < 51:
        p0, p1 = p1, 2 * p1 + p0
        a.append(p1)
        k += 1
        
    return a
     
t = input() 
all = seq()
while t:
    try:
        print all[input()]
        t -= 1
    except:
        break

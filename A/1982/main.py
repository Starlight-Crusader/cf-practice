t = int(input())

while t > 0:
    ss = []
    
    sl1 = input()
    sl2 = input()

    ss.append([int(score) for score in sl1.split(' ')])
    ss.append([int(score) for score in sl2.split(' ')])

    lead = []
    for ssi in ss:
        if (ssi[0] > ssi[1]):
            lead.append(0)
        else:
            lead.append(1)

    if (lead[0] != lead[1]):
        print("NO")
    else:
        print("YES")

    t -= 1
import math

t = int(input())

while (t > 0):
    types = [int(type) for type in input().split(' ')]

    tent_cnt = types[0]

    ntents_for_extr = math.ceil(types[1] / 3)
    if ntents_for_extr * 3 - types[1] <= types[2]:
        tent_cnt += ntents_for_extr
        types[2] -= (tent_cnt - types[0]) * 3 - types[1]
        
        tent_cnt += math.ceil(types[2] / 3)
    else:
        tent_cnt = -1

    print(tent_cnt)

    t -= 1

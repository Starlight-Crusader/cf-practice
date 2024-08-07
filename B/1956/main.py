t = int(input())

while (t > 0):
    n = int(input())

    cc = [0 for _ in range(n)]
 
    in_line = input()

    score = 0
    for cv in [int(c) for c in in_line.split(' ')]:
        cc[cv - 1] += 1

        if cc[cv - 1] == 2:
            score += 1

    print(score)

    t -= 1
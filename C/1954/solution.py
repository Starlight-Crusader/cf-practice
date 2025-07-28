t = int(input())

while t > 0:
    t -= 1
    x = input()
    y = input()

    nx = ""
    ny = ""

    for pos in range(len(x)):
        nsx = nx + x[pos:]
        nsy = ny + y[pos:]

        sx = nx + y[pos] + x[pos+1:]
        sy = ny + x[pos] + y[pos+1:]

        if (int(sx) * int(sy) > int(nsx) * int(nsy)):
            nx += y[pos]
            ny += x[pos]
        else:
            nx += x[pos]
            ny += y[pos]

    print(f"{nx}\n{ny}" if int(nx) > int(ny) else f"{ny}\n{nx}")

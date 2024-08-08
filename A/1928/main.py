t = int(input())

while (t > 0):
    sides = [int(token) for token in input().split(' ')]

    ponew = False
    for i in range(2):

        if sides[i] % 2 == 0:
            new_sides = [int(sides[i] / 2), sides[1 - i] * 2]

            if sorted(sides) != sorted(new_sides):
                ponew = True

    if ponew:
        print("YES")
    else:
        print("NO")

    t -= 1
t = int(input())

while (t > 0):
    n = int(input())

    grid = [[False for _ in range(2 * n)] for _ in range(2 * n)]

    vp = True
    for i in range(2 * n):

        if i % 2 == 0:
            vp = not vp

        hp = vp

        for j in range(2 * n):

            if j % 2 == 0:
                hp = not hp

            grid[i][j] = hp

    for i in range(2 * n):
        for j in range(2 * n):

            if grid[i][j]:
                print('#', end="")
            else:
                print('.', end="")

        print()

    t -= 1
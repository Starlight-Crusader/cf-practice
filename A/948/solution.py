dim_in = input().split()
r, c = int(dim_in[0]), int(dim_in[1])

field = []

EMPTY = '.'
SHEEP = 'S'
WOLF = 'W'
DOG = 'D'

for _ in range(r):
    field.append(list(input()))

dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

possible = True
for i in range(r):
    for j in range(c):
        if field[i][j] == SHEEP:
            for dir in dirs:
                di, dj = i + dir[0], j + dir[1]
                if (di >= 0 and di <= r - 1) and (dj >= 0 and dj <= c - 1):
                    if field[di][dj] == WOLF:
                        possible = False
                    elif field[di][dj] == EMPTY:
                        field[di][dj] = DOG

if possible:
    print("YES")
    for r in field:
        for c in r:
            print(c, end='')
        print()
else:
    print("NO")

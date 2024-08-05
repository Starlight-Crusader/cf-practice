t = int(input())

while (t > 0):
    time24 = [int(item) for item in input().split(':')]

    time12 = []
    
    time12.append(time24[0] % 12)
    if time12[0] == 0:
        time12[0] = 12

    time12.append(time24[1])

    half = ""
    if (time24[0] >= 12):
        half = "PM"
    else:
        half = "AM"

    lz = ['', '']
    for i in range(2):
        if time12[i] < 10:
            lz[i] = '0'

    print(f"{lz[0]}{time12[0]}:{lz[1]}{time12[1]} {half}")

    t -= 1
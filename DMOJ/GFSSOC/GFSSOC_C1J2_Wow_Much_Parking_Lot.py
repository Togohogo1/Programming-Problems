x = y = 0

for i in range(int(input())):
    direc = input()
    val = int(input())

    if direc == "North":
        y += val
    if direc == "South":
        y -= val
    if direc == "East":
        x += val
    if direc == "West":
        x -= val

print(x, y)

r = c = 0
x = y = -1
xp = yp = 0

c, r = map(int, input().split())

while True:
    x, y = map(int, input().split())

    if x == 0 and y == 0:
        break

    xp += x
    yp += y

    if xp >= c:
        xp = c
    elif xp <= 0:
        xp = 0

    if yp >= r:
        yp = r
    elif yp <= 0:
        yp = 0

    print(xp, yp)

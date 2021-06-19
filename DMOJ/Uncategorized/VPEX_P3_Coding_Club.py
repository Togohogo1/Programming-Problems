from math import gcd, sqrt


def lcm(a, b):
    return (a * b) / gcd(a, b)


screenW, screenH = map(int, input().split())
logoW, logoH = map(int, input().split())
x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())

dX = dY = 0

if x2 == 0:
    dX = 0
    dY = y2*2*(screenH-logoH) / y2
elif y2 == 0:
    dX = x2*2*(screenW-logoW) / x2
    dY = 0
else:
    dX = lcm(x2*2*(screenH-logoH), y2*2*(screenW-logoW)) / x2
    dY = lcm(x2*2*(screenH-logoH), y2*2*(screenW-logoW)) / y2

print(f"{sqrt(dX*dX + dY*dY):.6f}".replace(".", "")[:6])

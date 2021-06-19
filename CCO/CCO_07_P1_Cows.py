from math import sqrt, ceil


def dist(a, b):
    return sqrt((b[0] - a[0])**2 + (b[1] - a[1])**2)


def orient(p1, p2, p3):
    if (p2[1]-p1[1])*(p3[0]-p2[0]) - (p3[1]-p2[1])*(p2[0]-p1[0]) < 0:
        return 1  # CCW

    return 0


def convex_hull(points):
    conv_hull = []
    hull_idx = []

    t1 = 0
    t2 = 0

    while True:
        hull_idx.append(t2)
        t2 = (t1+1) % len(points)

        for i in range(len(points)):
            if orient(points[t1], points[t2], points[i]) == 1:
                t2 = i

        t1 = t2

        if t2 == 0:
            break

    for i in hull_idx:
        conv_hull.append(points[i])

    return conv_hull


cows = []
ans = 0

N = int(input())

for i in range(N):
    x, y = map(int, input().split())
    cows.append((x, y))

cows.sort()

pasture = convex_hull(cows)
pasture.reverse()
pasture.append(pasture[0])

# Shoelace Formula
for i in range(len(pasture)-1):
    ans += pasture[i][0]*pasture[i+1][1]
    ans -= pasture[i+1][0]*pasture[i][1]

print(ans//100)

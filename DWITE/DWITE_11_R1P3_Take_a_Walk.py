from math import sqrt, ceil


def dist(p1, p2):
    return sqrt((p2[0] - p1[0])**2 + (p2[1] - p1[1])**2)


def findPoint(p1, p2):
    if p2[0] == p1[0]:
        return (p2[0], cy)
    elif p2[1] == p1[1]:
        return (cx, p1[1])

    a = (p2[1]-p1[1]) / (p2[0]-p1[0])
    b = p1[1] - a*p1[0]
    c = cy + (1/a)*cx

    return ((a*(c-b) / (a*a + 1)), ((b + a*a*c) / (a*a + 1)))


for i in range(5):
    minDist = 999999999
    points = []

    N = int(input())

    for i in range(N):
        x, y = map(int, input().split())
        points.append((x, y))

    cx, cy = map(int, input().split())

    for i in range(N):
        minDist = min(minDist, dist((points[i][0], points[i][1]), (cx, cy)))

    for i in range(N-1):
        point = findPoint(points[i], points[i+1])

        if points[i][0] <= point[0] <= points[i+1][0] and points[i][1] <= point[1] <= points[i+1][1]:
            minDist = min(minDist, dist(point, (cx, cy)))

    print(f"{minDist:.2f}")

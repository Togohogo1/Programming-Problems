import math

min_dist = 100_000_000
pts = []

N = int(input())

for i in range(N):
    x, y = map(int, input().split())
    pts.append([x, y])

for i in range(0, N):
    for j in range(i+1, N):
        min_dist = min(min_dist, max(abs(pts[i][0] - pts[j][0]), abs(pts[i][1] - pts[j][1])))

print(min_dist ** 2)

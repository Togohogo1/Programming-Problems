import math

final = 0
coords = []

for i in range(int(input())):
    xy = list(map(int, input().split()))
    coords.append(xy)

coords.append(coords[0])

for i in range(len(coords)-1):
    final += coords[i][0]*coords[i+1][1] - coords[i][1]*coords[i+1][0]

print(math.ceil(abs(final/2)))

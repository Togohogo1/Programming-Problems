points = []
areas = []

for i in range(int(input())):
    x, y = map(int, input().split())
    points.append((x, y))

for x1, y1 in points:
    for x2, y2 in points:
        if (x1, y1) != (x2, y2):
            if (x1, y2) in points or (x2, y1) in points:
                areas.append(abs(x2-x1)*abs(y2-y1))

print(max(areas))
